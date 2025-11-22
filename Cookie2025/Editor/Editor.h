#pragma once
#include <Core/Framework.h>
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlgpu3.h>
#include <Editor/EditorUI/FileExplorerWindow.h>

namespace cookie
{
	namespace editor
	{
		class Editor : public core::Framework
		{
			SDL_Window* window = nullptr;
			SDL_GPUDevice* gpuDevice = nullptr;
			FileExplorerWindow fileExplorerWindow;
		public:
			Editor() {}
			virtual void Initialize() override;
			virtual void Update(core::FrameContext context) override;
			virtual void Destroy() override;
		};
	}
}