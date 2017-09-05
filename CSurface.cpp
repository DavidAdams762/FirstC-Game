#include "CSurface.h"

CSurface::CSurface() {
}

SDL_Surface* CSurface::onLoad(char* File){
	SDL_Surface* ecranTemp = NULL;
	SDL_Surface* ecranReturn = NULL;

	if((ecranTemp = IMG_Load(File)) == NULL ){
		return NULL;
	}
	ecranReturn = SDL_DisplayFormatAlpha(ecranTemp);
	SDL_FreeSurface(ecranTemp);

	return ecranReturn;
}

bool CSurface::onDraw(SDL_Surface* ecran, SDL_Surface* source, int x, int y){
	if(ecran == NULL || source == NULL){
		return false;
	}
	SDL_Rect DestR;
	DestR.x = x;
	DestR.y = y;

	SDL_BlitSurface(source, NULL, ecran, &DestR);

	return true;
}

bool CSurface::onDraw(SDL_Surface* ecran, SDL_Surface* source, int x, int y, int x2, int y2, int width, int heigth){
	if(ecran == NULL || source == NULL){
		return false;
	}
	SDL_Rect DestR;
	DestR.x = x;
	DestR.y = y;

	SDL_Rect SrcR;
	SrcR.x = x2;
	SrcR.y = y2;
	SrcR.w = width;
	SrcR.h = heigth;

	SDL_BlitSurface(source, &SrcR, ecran, &DestR);

	return true;
}

bool CSurface::transparent(SDL_Surface* surface, int r, int g, int b){
	if(surface == NULL){
		return false;
	}

	SDL_SetColorKey(surface, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(surface->format,r,g,b));
	//SDL_SetAlpha(surface, SDL_RLEACCEL, 255);
	return true;
}

SDL_Surface* CSurface::surfacePolice(string file, int size, string text, SDL_Color couleur) {

	//Ouvre la police
	TTF_Font* police = TTF_OpenFont(file.c_str(), size);

	//Ecriture du texte passé dans une surface
	SDL_Surface* surfaceText = TTF_RenderText_Blended(police, text.c_str(), couleur);

	//Libère la mémoire utilisé par la police
	TTF_CloseFont(police);

	//Retourne la surface texte
	return surfaceText;
}

void CSurface::collage(SDL_Surface* source, SDL_Surface* destination, int destinationX, int destinationY) {

	//Si la source est null == Erreur
	if(source == NULL) {
	cout << "La source est vide, impossible de Blitter" << endl;
	return;
	}

	//Si la destination est null
	if(destination == NULL) {
		//Utilise la surface de la fenêtre
		destination = SDL_GetVideoSurface();
	}

	//Zone destination
	SDL_Rect destinationRect;
	destinationRect.x = destinationX;
	destinationRect.y = destinationY;

	//Applique une surface
	SDL_BlitSurface(source, NULL, destination, &destinationRect);
}

void CSurface::collage(SDL_Surface* source, SDL_Surface* destination, int destinationX, int destinationY, int sourceX, int sourceY, int sourceH, int sourceW) {

	//Si la source est null == Erreur
	if(source == NULL) {
	cout << "La source est vide, impossible de coller" << endl;
	return;
	}

	//Si la destination est null
	if(destination == NULL) {

	//Utilise la surface de la fenêtre
	destination = SDL_GetVideoSurface();
	}

	//Zone source
	SDL_Rect sourceRect;
	sourceRect.x = sourceX;
	sourceRect.y = sourceY;
	sourceRect.h = sourceH;
	sourceRect.w = sourceW;

	//Zone destination
	SDL_Rect destinationRect;
	destinationRect.x = destinationX;
	destinationRect.y = destinationY;

	//Applique une surface
	SDL_BlitSurface(source, &sourceRect, destination, &destinationRect);
}

