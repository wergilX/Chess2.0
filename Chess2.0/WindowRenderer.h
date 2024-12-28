#pragma once
#include <SDL3\SDL.h>
#include <memory>
#include "TextureManager.h"

class WindowRenderer
{
public:
	WindowRenderer();
	~WindowRenderer();
	
	void Clear();
	void Present();
	void Render(SDL_FRect dest_rect, std::string assetName) const;

	TextureManager& GetTextureManager();
	
private:
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
	std::unique_ptr<TextureManager> m_textureManager;// todo
};

