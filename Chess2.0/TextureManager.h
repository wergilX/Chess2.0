#pragma once
#include <SDL3/SDL.h>
#include <unordered_map>
#include <optional>
#include <string>
#include <memory>

class TextureManager
{
public:
	TextureManager(SDL_Renderer* renderer);

	SDL_Texture* GetAsset(std::string assetName);
	void Load(std::string assetName, std::string path);
	void clearAll();

private:
	SDL_Renderer* m_renderer;
	std::unordered_map<std::string, SDL_Texture*>m_textures;
};