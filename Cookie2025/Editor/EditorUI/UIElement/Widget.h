#pragma once
#include <string>
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlgpu3.h>
namespace cookie
{
	namespace editor
	{ 
		class Widget
		{
		protected:
			std::string tittle;
			float width = 0;
			float height = 0;
			float posX = 0;
			float posY = 0;
			bool hide = false;
			virtual void OnGui() = 0;
		public:
			Widget() {}
			void SetTittle(const std::string tittle)
			{
				this->tittle = tittle;
			}

			void SetPos(float x, float y)
			{
				this->posX = x;
				this->posY = y;
			}

			void SetSize(float width, float height)
			{
				this->width = width;
				this->height = height;
			}

			void Update()
			{
				ImGui::Begin(tittle.c_str());
				OnGui();
				ImGui::End();
			}
			virtual ~Widget() {}
	};
}
}