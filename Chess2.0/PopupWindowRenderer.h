#pragma once
#include <SDL3\SDL.h>
#include <memory>
#include <string>

class PopupWindowRenderer
{
public:
	PopupWindowRenderer();
	~PopupWindowRenderer();

	void Clear();
	void Present();
	void Render(SDL_FRect dest_rect, std::string assetName) const;

private:
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
};
