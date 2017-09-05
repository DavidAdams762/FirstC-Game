#ifndef _MENU_H_
#define _MENU_H_
#include "CSurface.h"
#include <string.h>
#include <vector>
using namespace std;

struct menuElement {
    SDL_Surface* surfaceNormal;
    SDL_Surface* surfaceHover;
};
class Menu {
	private :
	    //Permet de savoir qu'elle lien a le focus
	    int m_currentIndex;

	    //Permet de savoir si un lien est sélectionné ou non
	    bool m_select;

	    //Position du menu à l'image
	    int m_posX;
	    int m_posY;

	    //Style du texte [taille + chemin vers la police]
	    int m_fontSize;
	    string m_fontPath;

	    //Couleur du texte
	    SDL_Color m_colorHover;
	    SDL_Color m_colorNormal;

	    //Tableau qui contiendra tous nos liens (structure menuElement)
	    vector <menuElement> m_menuElementList;
	public :
		Menu();
		void OnRender(SDL_Surface* ecran);

        //Ajout d'un lien
        void addRow(string text);

        //Setter [Défini les attributs]
        void setFontStyle(string font, const int size);
        void setPosition(int X, int Y);
        void setColor(SDL_Color colorNormal, SDL_Color colorHover);
        void setSelect(bool select);

        //Getter [Récupère les attributs]
        int getCurrentIndex();
        int getMenuSize();
        bool getIsSelect();

        //Mouvement
        void moveUp();
        void moveDown();
        void select();
};

#endif
