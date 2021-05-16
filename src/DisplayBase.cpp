/**
 *  Copyright (C) 2018  foxis (Andrius Mikonis <andrius.mikonis@gmail.com>)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include "DisplayBase.h"


TFT_eSPI tft = TFT_eSPI(135, 240); // init display
Button2 btn1(BUTTON_1);
Button2 btn2(BUTTON_2);
int btnCick = false;

void setupDisplay(){

	tft.init();
    tft.fontHeight(2);
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.drawString("Reflow oven", tft.width()/4, (tft.height() / 2) - (tft.height() / 4), 4);  //string,start x,start y, font weight {1;2;4;6;7;8}
	tft.drawString("controller", tft.width()/4, (tft.height() / 2) + (tft.height() / 4)*0, 4);  //string,start x,start y, font weight {1;2;4;6;7;8}
}
