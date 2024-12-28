#include "WindowRenderer.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

WindowRenderer::WindowRenderer()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		//return false;
	}

	if (SDL_CreateWindowAndRenderer("Chess", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &m_window, &m_renderer) < 0) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		//return SDL_APP_FAILURE;
	}

	m_textureManager = std::make_unique<TextureManager>(m_renderer);// todo
}
WindowRenderer::~WindowRenderer()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);

	SDL_Quit();
}

void WindowRenderer::Clear()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(m_renderer);
}

void WindowRenderer::Present()
{
	SDL_RenderPresent(m_renderer);
}

void WindowRenderer::Render(SDL_FRect dest_rect, std::string assetName) const
{
	SDL_RenderTexture(m_renderer, m_textureManager->GetAsset(assetName), NULL, &dest_rect);
}

TextureManager& WindowRenderer::GetTextureManager()
{
	return *m_textureManager; // todo
}
