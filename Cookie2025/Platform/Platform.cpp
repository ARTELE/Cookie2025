#include "Platform.h"
#include <Global.h>
using namespace cookie::platform;

void Platform::Initialize()
{
    CreateWindow();
	InitializeGraphicsContext();
}

void Windows::CreateWindow()
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
    {
       // printf("Error: SDL_Init(): %s\n", SDL_GetError());
        return;
    }

    float mainScale = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());
    SDL_WindowFlags windowFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY;
    SDL_Window* window = SDL_CreateWindow("Dear ImGui SDL3+SDL_GPU example", (int)(1280 * mainScale), (int)(800 * mainScale), windowFlags);
    if (window == nullptr)
    {
        //printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
        return;
    }
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_ShowWindow(window);

    global::GlobalContext::mainScale = mainScale;
    global::GlobalContext::window = window;
}

void Windows::InitializeGraphicsContext()
{
    SDL_GPUDevice* gpuDevice = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_DXIL | SDL_GPU_SHADERFORMAT_METALLIB, true, nullptr);
    if (gpuDevice == nullptr)
    {
        //printf("Error: SDL_CreateGPUDevice(): %s\n", SDL_GetError());
        return;
    }

    if (!SDL_ClaimWindowForGPUDevice(gpuDevice, global::GlobalContext::window))
    {
        //printf("Error: SDL_ClaimWindowForGPUDevice(): %s\n", SDL_GetError());
        return;
    }
    SDL_SetGPUSwapchainParameters(gpuDevice, global::GlobalContext::window, SDL_GPU_SWAPCHAINCOMPOSITION_SDR, SDL_GPU_PRESENTMODE_VSYNC);
    global::GlobalContext::gpuDevice = gpuDevice;
}