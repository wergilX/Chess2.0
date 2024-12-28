#include "TextureManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

TextureManager::TextureManager(SDL_Renderer* renderer) : m_renderer(renderer)
{
}

SDL_Texture* TextureManager::GetAsset(std::string assetName)
{
	if (m_textures.contains(assetName))
	{
		return m_textures.at(assetName);
	}

	return nullptr;
}

void TextureManager::Load(std::string assetName, std::string path)
{
	if (m_renderer == nullptr)
	{
		SDL_Log("TextureManager::m_renderer is nullptr");
		return;
	}

	int width, height, channels;
	unsigned char* imageData = stbi_load(path.c_str(), &width, &height, &channels, STBI_rgb_alpha);
	if (!imageData) {
		SDL_Log("Failed to load image %s: %s", path.c_str(), stbi_failure_reason());
		return;
	}

	SDL_Surface* surface = SDL_CreateSurfaceFrom(width, height, SDL_PIXELFORMAT_RGBA32, imageData, width * 4);
	if (!surface) {
		SDL_Log("SDL_CreateRGBSurfaceFrom Error: %s", SDL_GetError());
		stbi_image_free(imageData);
		return;
	}

	SDL_Texture* chessTexture = SDL_CreateTextureFromSurface(m_renderer, surface);
	stbi_image_free(imageData);
	if (!chessTexture) {
		SDL_Log("SDL_CreateTextureFromSurface Error: %s", SDL_GetError());
		return;
	}

	m_textures.insert({ assetName, chessTexture });
	SDL_Log("TextureManager::texture is loadet: %s", path.c_str());
}

void TextureManager::clearAll()
{
	for (auto& it : m_textures)
	{
		SDL_DestroyTexture(it.second);
		m_textures.clear();
	}
}

