#include "Menu.h"


Menu::Menu() {
}

void Menu::OnRender(SDL_Surface* ecran) {

	//Gère la position où les liens seront collés [un en dessous de l'autre]
	int rowY;

	//Pour tous les "liens" du menu
	for(int i = 0; i < this->getMenuSize(); i++) {

		rowY = this->m_posY + i * this->m_menuElementList[i].surfaceHover->h + 10;
		//Condition pour savoir qu'elle lien possède le focus
		if(this->m_currentIndex == i) {
			//Affiche la surfaceHover
			CSurface::onDraw(ecran,this->m_menuElementList[i].surfaceHover, this->m_posX, rowY);
		}
		else {
			//Affiche la surfaceNormal
			CSurface::onDraw(ecran, this->m_menuElementList[i].surfaceNormal, this->m_posX, rowY);
		}
	}
}

void Menu::addRow(std::string text) {
	//Créé un nouveau lien "m_el", le nom de la variable n'est pas important
	menuElement m_el;

	//Génére la surfaceHover
	m_el.surfaceHover = CSurface::surfacePolice(this->m_fontPath, this->m_fontSize,text, this->m_colorHover);

	//Génére la surfaceNormal
	m_el.surfaceNormal = CSurface::surfacePolice(this->m_fontPath, this->m_fontSize, text, this->m_colorNormal);

	//Ajout le nouveau lien dans le menu
	this->m_menuElementList.push_back(m_el);

	//Défini le currentIndex à 0
	this->m_currentIndex = 0;
}

void Menu::setFontStyle(std::string font, const int size) {
	this->m_fontSize = size;
	this->m_fontPath = font;
}

void Menu::setColor(SDL_Color colorNormal, SDL_Color colorHover) {
	this->m_colorNormal = colorNormal;
	this->m_colorHover = colorHover;
}

void Menu::setPosition(int x, int y) {
	this->m_posX = x;
	this->m_posY = y;
}

void Menu::setSelect(bool select) {
	this->m_select = select;
}
int Menu::getCurrentIndex() {
	return this->m_currentIndex;
}

int Menu::getMenuSize() {
	return this->m_menuElementList.size();
}


bool Menu::getIsSelect() {
	return this->m_select;
}

void Menu::moveUp() {
	if (this->m_currentIndex > 0)
        this->m_currentIndex = this->m_currentIndex - 1;
}

void Menu::moveDown() {
	if (this->m_currentIndex < this->getMenuSize() - 1)
        this->m_currentIndex = this->m_currentIndex + 1;
}
void Menu::select() {
    this->m_select = true;
}
