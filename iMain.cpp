#include "iGraphics.h"
#include <stdlib.h> 
//menu variable
int image;
int A, D, W, SPACE, ESC;
int logo;
char text1[] = "Enroll";
char text2[] = "Controls";
char text3[] = "Credits";
char text4[] = "Exit";
int menu = 0;
int controls = 1;
int screen = -3;
//game variable
int int5;
int cur_frame = 0;
int play[16];
int finalMonster[14];
int bgImage;
int playx = 10;
int playy = 10;
int x = 0;
int y = 0;
bool move = false;
bool jump = false;
int gy = 10;
int spd = 23;
int grvt = 1;
int vel = 0;
int quiz;
int xx;
int area = 0;
int attack = 0;
bool attacking = false;
int attackImg;
int attacktimer = 0;
int penImage;
int finalMonsterStand;
int finalMonsterAttack;
int finalMonsX = 2700;
int finalMonsY = 20;
int finalMonsHeight = 270;
int finalMonsWidth = 250;
bool finalMonsterAttacking = false;
bool isfinalMonsterJump = false;
int finalMonsJumpSpd = 25;
int monsterMove;
int minimonsterMove;
int secondfinalmonsterMove;
int secondminimonsterMove;
int paperImg;
bool isPaperThrown = false;
int paperX, paperY = -10;
int paperSpeed = 15;
int minipaperSpeed = 15;
int monsterHealth = 7;
bool monsterAlive = true;
int gameWinBannnerX;
int gameWinBannerY;
int nxtLblBtnW;
int nxtLblBtnH;
//level 2
int projectImage;
int pry = 800;
int prx;
int prpoint = 0;
int prcnt = 0;
bool l2 = 0;
bool sho = false;
void obstacle();
void finalMonsterAttackMove();
int sen2;
int penx = playx;
int peny = playy - 20;
bool space = false;
bool kolom = false;
bool salam = false;
int salamtimer = 0;
//---------------- second presentation work
int points = 0;
int life = 5;
int obsX = 0;
int obsY;
int obsHeight = 100;
int obsWidth = 70;
bool isObstacle = false;
int verimg;
int q1;
int q2;
//---------------- second presentation work
int quizx = 1600;
int quizy = 10;
bool ct = true;
//backbutton
int backButtonX = 20;
int backButtonY = 650;
int backButtonW = 120;
int backButtonH = 30;
bool ov = false;
int gameOverTimer = 0;
int int1;
int int2;
int int3;
int int4;
int tm = 200;
bool keyp = false;
int CNT = 0;
bool salamTriggered = false;
//mini monster vars
int miniMonsterStand;
int miniMonsterAttack;
int miniMonsX = 2700;
int miniMonsY = 40;
int miniMonsHeight = 200;
int miniMonsWidth = 180;
bool miniMonsterAttacking = false;
bool isminiMonsterJump = false;
int miniMonsJumpSpd = 25;
int minimonsterPic;
int minimonsterHealth = 5;
bool minimonsterAlive = true;
//senior
int sen;
int senx = 2200;
int seny = 10;
int senw = 220;
int senh = 270;
//secod mons
bool secondfinalmonsterAlive = true;
int secondfinalmonsterPic;
int secondfinalMonsterStand;
int secondfinalMonsterAttack;
int secondfinalMonsX = 2700;
int secondfinalMonsY = 40;
int secondfinalMonsHeight = 200;
int secondfinalMonsWidth = 180;
bool secondfinalMonsterAttacking = false;
bool issecondfinalMonsterJump = false;
int secondfinalMonsJumpSpd = 25;
int secondfinalmonsterHealth = 7;

//second mini
bool secondminimonsterAlive = true;
int secondminimonsterPic;
int secondminiMonsterStand;
int secondminiMonsterAttack;
int secondminiMonsX = 2700;
int secondminiMonsY = 40;
int secondminiMonsHeight = 200;
int secondminiMonsWidth = 180;
bool secondminiMonsterAttacking = false;
bool issecondminiMonsterJump = false;
int secondminiMonsJumpSpd = 25;
int secondminimonsterHealth = 5;

//button code
void drawEnrollButton(int x, int y, int width, int height, char* title) {
	// shadow
	iSetColor(180, 150, 100);
	iFilledRectangle(x + 5, y - 5, width, height);

	// btn bg
	iSetColor(255, 230, 170);
	iFilledRectangle(x, y, width, height);

	// border
	iSetColor(180, 120, 80);
	iRectangle(x, y, width, height);

	//txt
	iSetColor(50, 40, 40);
	iText(x + width / 2 - 25, y + height / 2 - 5, title, GLUT_BITMAP_HELVETICA_18);
}
void drawControlButton(int x, int y, int width, int height, char* title) {

	iSetColor(180, 150, 100);
	iFilledRectangle(x + 5, y - 5, width, height);

	iSetColor(255, 230, 170);
	iFilledRectangle(x, y, width, height);

	iSetColor(180, 120, 80);
	iRectangle(x, y, width, height);

	iSetColor(50, 40, 40);
	iText(x + width / 2 - 35, y + height / 2 - 5, title, GLUT_BITMAP_HELVETICA_18);
}
void drawCreditButton(int x, int y, int width, int height, char* title) {

	iSetColor(180, 150, 100);
	iFilledRectangle(x + 5, y - 5, width, height);

	iSetColor(255, 230, 170);
	iFilledRectangle(x, y, width, height);

	iSetColor(180, 120, 80);
	iRectangle(x, y, width, height);

	iSetColor(50, 40, 40);
	iText(x + width / 2 - 30, y + height / 2 - 5, title, GLUT_BITMAP_HELVETICA_18);
}
void drawExitButton(int x, int y, int width, int height, char* title) {

	iSetColor(180, 150, 100);
	iFilledRectangle(x + 5, y - 5, width, height);

	iSetColor(255, 230, 170);
	iFilledRectangle(x, y, width, height);

	iSetColor(180, 120, 80);
	iRectangle(x, y, width, height);

	iSetColor(50, 40, 40);
	iText(x + width / 2 - 15, y + height / 2 - 5, title, GLUT_BITMAP_HELVETICA_18);
}


void showGameTitle() {


	iShowImage(450, 400, 300, 200, logo);
	logo = iLoadImage("logo.png");
}

void drawRoundedPanel(int x, int y, int width, int height, int radius, int r, int g, int b) {
	iSetColor(r, g, b);
	iFilledRectangle(x + radius, y, width - 2 * radius, height);
	iFilledRectangle(x, y + radius, radius, height - 2 * radius);
	iFilledRectangle(x + width - radius, y + radius, radius, height - 2 * radius);

	iFilledCircle(x + radius, y + radius, radius);
	iFilledCircle(x + width - radius, y + radius, radius);
	iFilledCircle(x + radius, y + height - radius, radius);
	iFilledCircle(x + width - radius, y + height - radius, radius);
}

void playerpic()
{
	for (int i = 0; i < 16; i++)
	{
		char playname[20];
		sprintf_s(playname, "player\\%d.1.png", i + 1);
		play[i] = iLoadImage(playname);
	}
	//monster pic load
	for (int j = 0; j < 14; j++)
	{
		char playname[20];
		sprintf_s(playname, "player\\%d.png", j + 1);
		finalMonster[j] = iLoadImage(playname);
	}



	bgImage = iLoadImage("plaza.png");
	quiz = iLoadImage("quiz.png");
	attackImg = iLoadImage("attack.png");
	penImage = iLoadImage("pen.png");
	finalMonsterStand = iLoadImage("monsterStand.png");
	finalMonsterAttack = iLoadImage("10.attack.png");
	paperImg = iLoadImage("paper.png");
	monsterMove = finalMonsterStand;

	verimg = iLoadImage("pen2.png");
	q1 = iLoadImage("q1.png");
	q2 = iLoadImage("q2.png");
	int1 = iLoadImage("intro1.png");
	int2 = iLoadImage("intro2.png");
	int3 = iLoadImage("sem1.png");
	int4 = iLoadImage("sem2.png");
	projectImage = iLoadImage("project.png");
	minimonsterPic = iLoadImage("minimonster.png");
	sen = iLoadImage("2.png");
	sen2 = iLoadImage("sen2.png");
	secondfinalmonsterPic = iLoadImage("secondmonster.png");
	secondminimonsterPic = iLoadImage("secondmini.png");
	image = iLoadImage("menu.png");
	int5 = iLoadImage("end.png");
}
void proj()
{
	if (prcnt < 5){
		if (pry <= 0) {
			prx = (rand() % 1200) - x;
			pry = 800;
			prcnt++;
		}
		else {
			pry -= 6;
		}
	}

}

void col()
{

	int projW = 50;
	int projH = 50;
	int playerW = 120;
	int playerH = 270;
	if (playx < prx + projW + x &&
		playx + playerW > prx + x &&
		playy < pry + projH &&
		playy + playerH > pry)
	{
		pry = 750;
		prx = (rand() % 1200) - x;
		prpoint++;
	}

}
void prov()
{
	if (area == 8 && prpoint < 15)
		ov = true;
}



void iDraw()
{
	iClear();
	if (screen == -3){

		iClear();
		iFilledRectangle(10, 10, 100, 100);
		iSetColor(255, 255, 255);
		iShowImage(0, 0, 1200, 700, image);
		

		int buttonWidth = 160;
		int buttonHeight = 60;
		int x = 520;
		int y = 340;

		//btns
		drawEnrollButton(x, y, buttonWidth, buttonHeight, text1);
		drawControlButton(x, y - 80, buttonWidth, buttonHeight, text2);
		drawCreditButton(x, y - 160, buttonWidth, buttonHeight, text3);
		drawExitButton(x, y - 240, buttonWidth, buttonHeight, text4);

		//game title
		showGameTitle();

	}

	// controls page 
	if (screen == -2) {
		iClear();
		iShowImage(0, 0, 1200, 700, image); //bg pic
		

		// bg container card
		iSetColor(59, 98, 85);
		iFilledRectangle(100, 100, 1000, 400);

		//title
		iSetColor(255, 255, 255);
		iText(520, 460, "Controls", GLUT_BITMAP_TIMES_ROMAN_24);

		//control icon
		int iconY = 350;
		int iconSize = 50;

		A = iLoadImage("A.png");
		D = iLoadImage("D.png");
		W = iLoadImage("W.png");
		SPACE = iLoadImage("SPACE.png");
		ESC = iLoadImage("ESC.png");

		iShowImage(180, iconY, iconSize, iconSize, A);
		iText(250, iconY + 15, "Move Left", GLUT_BITMAP_HELVETICA_18);

		iShowImage(180, iconY - 60, iconSize, iconSize, D);
		iText(250, iconY - 45, "Move Right", GLUT_BITMAP_HELVETICA_18);

		iShowImage(180, iconY - 120, iconSize, iconSize, W);
		iText(250, iconY - 105, "Jump", GLUT_BITMAP_HELVETICA_18);

		iShowImage(180, iconY - 180, iconSize, iconSize, SPACE);
		iText(250, iconY - 165, "Attack (Space)", GLUT_BITMAP_HELVETICA_18);

		iShowImage(180, iconY - 240, iconSize, iconSize, ESC);
		iText(250, iconY - 225, "Pause (ESC)", GLUT_BITMAP_HELVETICA_18);

		//back btn
		iSetColor(200, 180, 100);
		iFilledRectangle(50, 50, 110, 40);

		iSetColor(255, 230, 170);
		iFilledRectangle(45, 55, 110, 40);

		iSetColor(50, 40, 40);
		iRectangle(45, 55, 110, 40);
		iText(70, 65, "Back", GLUT_BITMAP_HELVETICA_18);
	}


	if (screen == -1) {
		iClear();
		iShowImage(0, 0, 1200, 700, image);
		

		//container card
		drawRoundedPanel(300, 150, 600, 300, 20, 59, 98, 85);

		//title
		iSetColor(255, 215, 0);
		iText(500, 420, "CREDITS", GLUT_BITMAP_TIMES_ROMAN_24);

		//credit 
		iSetColor(255, 255, 255);
		iText(350, 360, "Rejwanul Islam Rakib", GLUT_BITMAP_HELVETICA_18);
		iText(350, 335, "Roll : 00724105101002", GLUT_BITMAP_HELVETICA_18);

		iText(350, 290, "Raiyan Anam", GLUT_BITMAP_HELVETICA_18);
		iText(350, 265, "Roll : 00724105101003", GLUT_BITMAP_HELVETICA_18);

		iText(350, 220, "Azmaeen Mahtab Ezaz", GLUT_BITMAP_HELVETICA_18);
		iText(350, 195, "Roll : 00724105101004", GLUT_BITMAP_HELVETICA_18);

		// back btn
		iSetColor(200, 180, 100); //shadow
		iFilledRectangle(50, 50, 110, 40);

		iSetColor(255, 230, 170); //main
		iFilledRectangle(45, 55, 110, 40);
		//border
		iSetColor(50, 40, 40);
		iRectangle(45, 55, 110, 40);

		iText(70, 65, "Back", GLUT_BITMAP_HELVETICA_18);
	}
	if (screen == 0)
	{
		iShowImage(0, 0, 1200, 700, int1);

		int boxWidth = 260;      // 2/6 of 1200 = 400 
		int boxHeight = 60;
		int boxX = (1200 - boxWidth) / 2;
		int boxY = 620;           // top middle area 

		// Outer rectangle (like pen box) 
		iSetColor(200, 180, 100);
		iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

		// Inner rectangle 
		iSetColor(255, 230, 170);
		iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

		// Border 
		iSetColor(50, 40, 40);
		iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

		// Text centered approximately 
		iSetColor(50, 40, 40);
		iText(boxX + 50, boxY + 20, "Press 'm' to continue",
			GLUT_BITMAP_HELVETICA_18);

	}
	else if (screen == 1)
	{
		iShowImage(0, 0, 1200, 700, int2);

		int boxWidth = 260;      // 2/6 of 1200 = 400 
		int boxHeight = 60;
		int boxX = (1200 - boxWidth) / 2;
		int boxY = 620;           // top middle area 

		// Outer rectangle (like pen box) 
		iSetColor(200, 180, 100);
		iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

		// Inner rectangle 
		iSetColor(255, 230, 170);
		iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

		// Border 
		iSetColor(50, 40, 40);
		iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

		// Text centered approximately 
		iSetColor(50, 40, 40);
		iText(boxX + 50, boxY + 20, "Press 'm' to continue",
			GLUT_BITMAP_HELVETICA_18);
	}
	else if (screen == 2)
	{
		iShowImage(0, 0, 1200, 700, int3);

		int boxWidth = 260;      // 2/6 of 1200 = 400 
		int boxHeight = 60;
		int boxX = (1200 - boxWidth) / 2;
		int boxY = 620;           // top middle area 

		// Outer rectangle (like pen box) 
		iSetColor(200, 180, 100);
		iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

		// Inner rectangle 
		iSetColor(255, 230, 170);
		iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

		// Border 
		iSetColor(50, 40, 40);
		iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

		// Text centered approximately 
		iSetColor(50, 40, 40);
		iText(boxX + 50, boxY + 20, "Press 'm' to continue",
			GLUT_BITMAP_HELVETICA_18);
	}
	else if (screen == 3)
	{

		if (area == 0){

			iShowImage(x, y, 3000, 1000, bgImage);
			int boxWidth = 150;      // 2/6 of 1200 = 400 
			int boxHeight = 60;
			int boxX = (1200 - boxWidth) / 2;
			int boxY = 620;           // top middle area 

			// Outer rectangle (like pen box) 
			iSetColor(200, 180, 100);
			iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

			// Inner rectangle 
			iSetColor(255, 230, 170);
			iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Border 
			iSetColor(50, 40, 40);
			iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Text centered approximately 
			iSetColor(50, 40, 40);
			iText(boxX + 50, boxY + 20, "Plaza",
				GLUT_BITMAP_HELVETICA_18);
			if (attacking)
				iShowImage(playx, playy, 220, 270, attackImg);
			else
				iShowImage(playx, playy, 220, 270, play[cur_frame]);
			if (ct)
				iShowImage(quizx + x, quizy, 190, 250, quiz);
			iShowImage(obsX + x, obsY, obsWidth, obsHeight, penImage);
			iShowImage(2500 + x, 10, senw, senh + 5, sen);
			if (salam)
			{

				int boxWidth = 260;      // 2/6 of 1200 = 400 
				int boxHeight = 60;
				int boxX = 600;
				int boxY = 400;           // top middle area 

				// Outer rectangle (like pen box) 
				iSetColor(200, 180, 100);
				iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

				// Inner rectangle 
				iSetColor(255, 230, 170);
				iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

				// Border 
				iSetColor(50, 40, 40);
				iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

				// Text centered approximately 
				iSetColor(50, 40, 40);
				iText(boxX + 50, boxY + 20, "Assalamualaikum Bhai",
					GLUT_BITMAP_HELVETICA_18);
				int midBoxWidth = 350;
				int midBoxHeight = 70;
				int midBoxX = 650; // center horizontally
				int midBoxY = 300;                      // somewhere near middle vertically

				// Outer box
				iSetColor(200, 180, 100);
				iFilledRectangle(midBoxX, midBoxY, midBoxWidth, midBoxHeight);

				// Inner box
				iSetColor(255, 230, 170);
				iFilledRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Border
				iSetColor(50, 40, 40);
				iRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Text
				iSetColor(50, 40, 40);
				iText(midBoxX + 50, midBoxY + 25, "Walaikumussalam. Ne kolom", GLUT_BITMAP_HELVETICA_18);
			}

		}
		if (area == 1)
		{
			iShowImage(x, y, 3000, 700, bgImage);
			int boxWidth = 180;      // 2/6 of 1200 = 400 
			int boxHeight = 60;
			int boxX = (1200 - boxWidth) / 2;
			int boxY = 620;           // top middle area 

			// Outer rectangle (like pen box) 
			iSetColor(200, 180, 100);
			iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

			// Inner rectangle 
			iSetColor(255, 230, 170);
			iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Border 
			iSetColor(50, 40, 40);
			iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Text centered approximately 
			iSetColor(50, 40, 40);
			iText(boxX + 50, boxY + 20, "Library",
				GLUT_BITMAP_HELVETICA_18);
			if (attacking)
				iShowImage(playx, playy, 240, 290, attackImg);
			else
				iShowImage(playx, playy, 240, 290, play[cur_frame]);

			if (ct)
				iShowImage(quizx + x, quizy, 190, 250, q1);
			iShowImage(obsX + x, obsY, obsWidth, obsHeight, penImage);
			//monster arrival
			if (playx >= 370 && playx <= 520 && x>-1800) {
				// Draw "Midterm Incoming" box
				int midBoxWidth = 270;
				int midBoxHeight = 70;
				int midBoxX = (1200 - midBoxWidth) / 2; // center horizontally
				int midBoxY = 450;                      // somewhere near middle vertically

				// Outer box
				iSetColor(200, 180, 100);
				iFilledRectangle(midBoxX, midBoxY, midBoxWidth, midBoxHeight);

				// Inner box
				iSetColor(255, 230, 170);
				iFilledRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Border
				iSetColor(50, 40, 40);
				iRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Text
				iSetColor(50, 40, 40);
				iText(midBoxX + 50, midBoxY + 25, "Midterm Boss Incoming", GLUT_BITMAP_HELVETICA_18);
			}
			//Mini Monster health show
			if (playx >= 520 || x == -1800)
			{

				iSetColor(200, 180, 100);
				iFilledRectangle(1030, 550, 155, 40);

				iSetColor(255, 230, 170);
				iFilledRectangle(1035, 545, 145, 40);

				iSetColor(50, 40, 40);
				char healthText[20];
				sprintf_s(healthText, "Mid Boss : %d", minimonsterHealth);
				iText(1040, 560, healthText, GLUT_BITMAP_HELVETICA_18);

			}
			//mini monster work start
			if (minimonsterAlive){
				iShowImage(miniMonsX + x, miniMonsY, miniMonsWidth, miniMonsHeight, minimonsterPic);
			}
			else
			{
				int midBoxWidth = 270;
				int midBoxHeight = 70;
				int midBoxX = (1200 - midBoxWidth) / 2; // center horizontally
				int midBoxY = 450;                      // somewhere near middle vertically

				// Outer box
				iSetColor(200, 180, 100);
				iFilledRectangle(midBoxX, midBoxY, midBoxWidth, midBoxHeight);

				// Inner box
				iSetColor(255, 230, 170);
				iFilledRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Border
				iSetColor(50, 40, 40);
				iRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Text
				iSetColor(50, 40, 40);
				iText(midBoxX + 50, midBoxY + 25, "Midterm passed!", GLUT_BITMAP_HELVETICA_18);
			}

			if (isPaperThrown) {
				iShowImage(paperX, paperY, 50, 50, paperImg);   // paper image
			}

		}
		if (area == 2)
		{
			iShowImage(x, y, 3000, 700, bgImage);
			int boxWidth = 150;      // 2/6 of 1200 = 400 
			int boxHeight = 60;
			int boxX = (1200 - boxWidth) / 2;
			int boxY = 620;           // top middle area 

			// Outer rectangle (like pen box) 
			iSetColor(200, 180, 100);
			iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

			// Inner rectangle 
			iSetColor(255, 230, 170);
			iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Border 
			iSetColor(50, 40, 40);
			iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Text centered approximately 
			iSetColor(50, 40, 40);
			iText(boxX + 50, boxY + 20, "RedX",
				GLUT_BITMAP_HELVETICA_18);
			if (attacking)
				iShowImage(playx, playy, 230, 300, attackImg);
			else
				iShowImage(playx, playy, 230, 300, play[cur_frame]);
			if (ct)
				iShowImage(quizx + x, quizy, 190, 250, q2);
			iShowImage(obsX + x, obsY, obsWidth, obsHeight, penImage);
			iShowImage(2500 + x, 10, senw+10, senh + 15, sen2);
			if (salam)
			{

				int boxWidth = 260;      // 2/6 of 1200 = 400 
				int boxHeight = 60;
				int boxX = 600;
				int boxY = 400;           // top middle area 

				// Outer rectangle (like pen box) 
				iSetColor(200, 180, 100);
				iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

				// Inner rectangle 
				iSetColor(255, 230, 170);
				iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

				// Border 
				iSetColor(50, 40, 40);
				iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

				// Text centered approximately 
				iSetColor(50, 40, 40);
				iText(boxX + 50, boxY + 20, "Assalamualaikum Bhai",
					GLUT_BITMAP_HELVETICA_18);
				int midBoxWidth = 350;
				int midBoxHeight = 70;
				int midBoxX = 650; // center horizontally
				int midBoxY = 300;                      // somewhere near middle vertically

				// Outer box
				iSetColor(200, 180, 100);
				iFilledRectangle(midBoxX, midBoxY, midBoxWidth, midBoxHeight);

				// Inner box
				iSetColor(255, 230, 170);
				iFilledRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Border
				iSetColor(50, 40, 40);
				iRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Text
				iSetColor(50, 40, 40);
				iText(midBoxX + 50, midBoxY + 25, "Walaikumussalam. Ne kolom", GLUT_BITMAP_HELVETICA_18);

			}
		}
		if (area == 3)
		{
			iShowImage(x, y, 3000, 1000, bgImage);
			int boxWidth = 180;      // 2/6 of 1200 = 400 
			int boxHeight = 60;
			int boxX = (1200 - boxWidth) / 2;
			int boxY = 620;           // top middle area 

			// Outer rectangle (like pen box) 
			iSetColor(200, 180, 100);
			iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

			// Inner rectangle 
			iSetColor(255, 230, 170);
			iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Border 
			iSetColor(50, 40, 40);
			iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Text centered approximately 
			iSetColor(50, 40, 40);
			iText(boxX + 50, boxY + 20, "Canteen",
				GLUT_BITMAP_HELVETICA_18);
			if (playx >= 370 && playx <= 520 && x>-1800) {
				// Draw "Midterm Incoming" box
				int midBoxWidth = 270;
				int midBoxHeight = 70;
				int midBoxX = (1200 - midBoxWidth) / 2; // center horizontally
				int midBoxY = 450;                      // somewhere near middle vertically

				// Outer box
				iSetColor(200, 180, 100);
				iFilledRectangle(midBoxX, midBoxY, midBoxWidth, midBoxHeight);

				// Inner box
				iSetColor(255, 230, 170);
				iFilledRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Border
				iSetColor(50, 40, 40);
				iRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Text
				iSetColor(50, 40, 40);
				iText(midBoxX + 25, midBoxY + 25, "Semester Boss Incoming", GLUT_BITMAP_HELVETICA_18);
			}
			//Monster health show
			if (playx >= 520 || x == -1800)
			{
				iSetColor(200, 180, 100);
				iFilledRectangle(1030, 550, 140, 40);

				iSetColor(255, 230, 170);
				iFilledRectangle(1035, 545, 130, 40);

				iSetColor(50, 40, 40);
				char healthText[20];
				sprintf_s(healthText, "Final Boss : %d", monsterHealth);
				iText(1045, 560, healthText, GLUT_BITMAP_HELVETICA_18);
			}
			if (attacking)
				iShowImage(playx, playy, 220, 270, attackImg);
			else
				iShowImage(playx, playy, 220, 270, play[cur_frame]);

			iShowImage(obsX + x, obsY, obsWidth, obsHeight, penImage);
			//Game win stats
			if (monsterHealth <= 0){

				iSetColor(200, 180, 100);
				iFilledRectangle(530, 410, 160, 40);

				iSetColor(255, 230, 170);
				iFilledRectangle(535, 405, 150, 40);

				iSetColor(50, 40, 40);
				char winText[50] = "1.1 Cracked!!";

				iText(545, 413, winText, GLUT_BITMAP_HELVETICA_18);

				//next semester btn

				iSetColor(200, 180, 100);
				iFilledRectangle(530, 300, 250, 50);

				iSetColor(255, 230, 170);
				iFilledRectangle(535, 295, 240, 50);

				iSetColor(50, 40, 40);
				char nextsemText[50] = "Move on to enroll in 1.2";

				iText(545, 310, nextsemText, GLUT_BITMAP_HELVETICA_18);

			}


			//printf("%d\n", x);   // printing screen point
			//final monster work
			if (monsterAlive){
				iShowImage(finalMonsX + x, finalMonsY, finalMonsWidth, finalMonsHeight, monsterMove);


			}

			if (isPaperThrown) {
				iShowImage(paperX, paperY, 50, 50, paperImg);   // paper image
			}

		}
		if (area == 4)
		{

			iShowImage(0, 0, 1200, 700, int4);

			int boxWidth = 280;      // 2/6 of 1200 = 400 
			int boxHeight = 60;
			int boxX = (1200 - boxWidth) / 2;
			int boxY = 620;           // top middle area 

			// Outer rectangle (like pen box) 
			iSetColor(200, 180, 100);
			iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

			// Inner rectangle 
			iSetColor(255, 230, 170);
			iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Border 
			iSetColor(50, 40, 40);
			iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Text centered approximately 
			iSetColor(50, 40, 40);
			iText(boxX + 50, boxY + 20, "Press 'm' & 'd' to continue",
				GLUT_BITMAP_HELVETICA_18);

		}
		if (area == 5)
		{
			iShowImage(x, y, 3000, 1000, bgImage);

			if (attacking)
				iShowImage(playx, playy, 230, 280, attackImg);
			else
				iShowImage(playx, playy, 230, 280, play[cur_frame]);

			if (ct)
				iShowImage(quizx + x, quizy, 190, 250, q1);
			iShowImage(obsX + (x + 5), obsY + 5, obsWidth, obsHeight, penImage);
			iShowImage(prx + x, pry, 50, 50, projectImage);
			col();
			if (playx >= 0 && playx <= 200)
			{
				int boxWidth = 460;      // 2/6 of 1200 = 400 
				int boxHeight = 70;
				int boxX = (1200 - boxWidth) / 2;
				int boxY = 540;           // top middle area 

				// Outer rectangle (like pen box) 
				iSetColor(200, 180, 100);
				iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

				// Inner rectangle 
				iSetColor(255, 230, 170);
				iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

				// Border 
				iSetColor(50, 40, 40);
				iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

				// Text centered approximately 
				iSetColor(50, 40, 40);
				iText(boxX + 50, boxY + 20, "Collect 15 project points to fight the final Boss", GLUT_BITMAP_HELVETICA_18);
			}
			int mboxWidth = 110;      // 2/6 of 1200 = 400 
			int mboxHeight = 60;
			int mboxX = (1200 - mboxWidth) / 2;
			int mboxY = 620;           // top middle area 

			// Outer rectangle (like pen box) 
			iSetColor(200, 180, 100);
			iFilledRectangle(mboxX, mboxY, mboxWidth, mboxHeight);

			// Inner rectangle 
			iSetColor(255, 230, 170);
			iFilledRectangle(mboxX + 5, mboxY + 5, mboxWidth - 10, mboxHeight - 10);

			// Border 
			iSetColor(50, 40, 40);
			iRectangle(mboxX + 5, mboxY + 5, mboxWidth - 10, mboxHeight - 10);

			// Text centered approximately 
			iSetColor(50, 40, 40);
			iText(mboxX + 25, mboxY + 20, "7A05",
				GLUT_BITMAP_HELVETICA_18);

		}
		if (area == 6)
		{
			iShowImage(x, y, 3000, 700, bgImage);
			int boxWidth = 180;      // 2/6 of 1200 = 400 
			int boxHeight = 60;
			int boxX = (1200 - boxWidth) / 2;
			int boxY = 620;           // top middle area 

			// Outer rectangle (like pen box) 
			iSetColor(200, 180, 100);
			iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

			// Inner rectangle 
			iSetColor(255, 230, 170);
			iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Border 
			iSetColor(50, 40, 40);
			iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Text centered approximately 
			iSetColor(50, 40, 40);
			iText(boxX + 50, boxY + 20, "C Block",
				GLUT_BITMAP_HELVETICA_18);
			if (attacking)
				iShowImage(playx, playy, 240, 290, attackImg);
			else
				iShowImage(playx, playy, 240, 290, play[cur_frame]);

			if (ct)
				iShowImage(quizx + x, quizy, 190, 250, q2);
			iShowImage(obsX + x, obsY, obsWidth, obsHeight, penImage);
			iShowImage(prx + x, pry, 50, 50, projectImage);
			col();
			//second monster arrival
			if (playx >= 370 && playx <= 520 && x>-1800) {
				// Draw "Midterm Incoming" box
				int midBoxWidth = 270;
				int midBoxHeight = 70;
				int midBoxX = (1200 - midBoxWidth) / 2; // center horizontally
				int midBoxY = 450;                      // somewhere near middle vertically

				// Outer box
				iSetColor(200, 180, 100);
				iFilledRectangle(midBoxX, midBoxY, midBoxWidth, midBoxHeight);

				// Inner box
				iSetColor(255, 230, 170);
				iFilledRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Border
				iSetColor(50, 40, 40);
				iRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Text
				iSetColor(50, 40, 40);
				iText(midBoxX + 50, midBoxY + 25, "Midterm Boss Incoming", GLUT_BITMAP_HELVETICA_18);
			}
			//Mini Monster health show
			if (playx >= 520 || x == -1800)
			{

				iSetColor(200, 180, 100);
				iFilledRectangle(1030, 550, 155, 40);

				iSetColor(255, 230, 170);
				iFilledRectangle(1035, 545, 145, 40);

				iSetColor(50, 40, 40);
				char healthText[20];
				sprintf_s(healthText, "Mid Boss : %d", secondminimonsterHealth);
				iText(1040, 560, healthText, GLUT_BITMAP_HELVETICA_18);

			}
			//mini monster work start
			if (secondminimonsterAlive){
				iShowImage(secondminiMonsX + x, secondminiMonsY, secondminiMonsWidth, secondminiMonsHeight, secondminimonsterPic);
			}
			else
			{
				int midBoxWidth = 270;
				int midBoxHeight = 70;
				int midBoxX = (1200 - midBoxWidth) / 2; // center horizontally
				int midBoxY = 450;                      // somewhere near middle vertically

				// Outer box
				iSetColor(200, 180, 100);
				iFilledRectangle(midBoxX, midBoxY, midBoxWidth, midBoxHeight);

				// Inner box
				iSetColor(255, 230, 170);
				iFilledRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Border
				iSetColor(50, 40, 40);
				iRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Text
				iSetColor(50, 40, 40);
				iText(midBoxX + 50, midBoxY + 25, "Midterm passed!", GLUT_BITMAP_HELVETICA_18);
			}

			if (isPaperThrown) {
				iShowImage(paperX, paperY, 50, 50, paperImg);   // paper image
			}
			
		}
		if (area == 7)
		{
			iShowImage(x, y, 3000, 700, bgImage);
			int boxWidth = 180;      // 2/6 of 1200 = 400 
			int boxHeight = 60;
			int boxX = (1200 - boxWidth) / 2;
			int boxY = 620;           // top middle area 

			// Outer rectangle (like pen box) 
			iSetColor(200, 180, 100);
			iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

			// Inner rectangle 
			iSetColor(255, 230, 170);
			iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Border 
			iSetColor(50, 40, 40);
			iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Text centered approximately 
			iSetColor(50, 40, 40);
			iText(boxX + 50, boxY + 20, "B Block",
				GLUT_BITMAP_HELVETICA_18);
			if (attacking)
				iShowImage(playx, playy, 230, 300, attackImg);
			else
				iShowImage(playx, playy, 230, 300, play[cur_frame]);
			if (ct)
				iShowImage(quizx + x, quizy, 190, 250, quiz);
			iShowImage(obsX + (x + 10), obsY + 4, obsWidth, obsHeight, penImage);
			iShowImage(prx + x, pry, 50, 50, projectImage);
			col();
		}
		if (area == 8)
		{
			iShowImage(x, y, 3000, 1000, bgImage);

			if (attacking)
				iShowImage(playx, playy, 220, 270, attackImg);
			else
				iShowImage(playx, playy, 240, 290, play[cur_frame]);

			iShowImage(obsX + (x + 10), obsY - 5, obsWidth, obsHeight, penImage);

			prov();
			int boxWidth = 210;      // 2/6 of 1200 = 400 
			int boxHeight = 60;
			int boxX = (1200 - boxWidth) / 2;
			int boxY = 620;           // top middle area 

			// Outer rectangle (like pen box) 
			iSetColor(200, 180, 100);
			iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

			// Inner rectangle 
			iSetColor(255, 230, 170);
			iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Border 
			iSetColor(50, 40, 40);
			iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

			// Text centered approximately 
			iSetColor(50, 40, 40);
			iText(boxX + 50, boxY + 20, "Hawa Bhaban",
				GLUT_BITMAP_HELVETICA_18);
			if (prpoint < 15) {
				// Draw "project point les than 15" box
				int midBoxWidth = 270;
				int midBoxHeight = 70;
				int midBoxX = (1200 - midBoxWidth) / 2; // center horizontally
				int midBoxY = 450;                      // somewhere near middle vertically

				// Outer box
				iSetColor(200, 180, 100);
				iFilledRectangle(midBoxX, midBoxY, midBoxWidth, midBoxHeight);

				// Inner box
				iSetColor(255, 230, 170);
				iFilledRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Border
				iSetColor(50, 40, 40);
				iRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

				// Text
				iSetColor(50, 40, 40);
				iText(midBoxX + 10, midBoxY + 25, "Project Point Less than 15!!", GLUT_BITMAP_HELVETICA_18);
			}
				if (playx >= 370 && playx <= 520 && x>-1800) {
					// Draw "Midterm Incoming" box
					int midBoxWidth = 270;
					int midBoxHeight = 70;
					int midBoxX = (1200 - midBoxWidth) / 2; // center horizontally
					int midBoxY = 450;                      // somewhere near middle vertically

					// Outer box
					iSetColor(200, 180, 100);
					iFilledRectangle(midBoxX, midBoxY, midBoxWidth, midBoxHeight);

					// Inner box
					iSetColor(255, 230, 170);
					iFilledRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

					// Border
					iSetColor(50, 40, 40);
					iRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

					// Text
					iSetColor(50, 40, 40);
					iText(midBoxX + 50, midBoxY + 25, "Final Boss Incoming", GLUT_BITMAP_HELVETICA_18);

				}
				//Mini Monster health show
				if (playx >= 520 || x == -1800)
				{

					iSetColor(200, 180, 100);
					iFilledRectangle(1030, 550, 155, 40);

					iSetColor(255, 230, 170);
					iFilledRectangle(1035, 545, 145, 40);

					iSetColor(50, 40, 40);
					char healthText[20];
					sprintf_s(healthText, "Final Boss : %d", secondfinalmonsterHealth);
					iText(1040, 560, healthText, GLUT_BITMAP_HELVETICA_18);

				}
				//mini monster work start
				if (secondfinalmonsterAlive){
					iShowImage(secondfinalMonsX + x, secondfinalMonsY, secondfinalMonsWidth, secondfinalMonsHeight, secondfinalmonsterPic);
				}
				else
				{
					int midBoxWidth = 270;
					int midBoxHeight = 70;
					int midBoxX = (1200 - midBoxWidth) / 2; // center horizontally
					int midBoxY = 450;                      // somewhere near middle vertically

					// Outer box
					iSetColor(200, 180, 100);
					iFilledRectangle(midBoxX, midBoxY, midBoxWidth, midBoxHeight);

					// Inner box
					iSetColor(255, 230, 170);
					iFilledRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

					// Border
					iSetColor(50, 40, 40);
					iRectangle(midBoxX + 5, midBoxY + 5, midBoxWidth - 10, midBoxHeight - 10);

					// Text
					iSetColor(50, 40, 40);
					iText(midBoxX + 50, midBoxY + 25, "1.2 Cracked!", GLUT_BITMAP_HELVETICA_18);
					iSetColor(200, 180, 100);
					iFilledRectangle(530, 300, 250, 50);

					iSetColor(255, 230, 170);
					iFilledRectangle(535, 295, 240, 50);

					iSetColor(50, 40, 40);
					char nextsemText[50] = "Move on to finish 1st year";

					iText(545, 310, nextsemText, GLUT_BITMAP_HELVETICA_18);
				}

				if (isPaperThrown) {
					iShowImage(paperX, paperY, 50, 50, paperImg);   // paper image
				}

			}
			if (area == 9)
			{
				iShowImage(0, 0, 1200, 700, int5);

				int boxWidth = 280;      // 2/6 of 1200 = 400 
				int boxHeight = 60;
				int boxX = (1200 - boxWidth) / 2;
				int boxY = 620;           // top middle area 

				// Outer rectangle (like pen box) 
				iSetColor(200, 180, 100);
				iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

				// Inner rectangle 
				iSetColor(255, 230, 170);
				iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

				// Border 
				iSetColor(50, 40, 40);
				iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

				// Text centered approximately 
				iSetColor(50, 40, 40);
				iText(boxX + 50, boxY + 20, "Press 'back' to continue",
					GLUT_BITMAP_HELVETICA_18);
			}
		
			//back button
			iSetColor(200, 180, 100);
			iFilledRectangle(20, 650, 120, 40);

			iSetColor(255, 230, 170);
			iFilledRectangle(25, 645, 110, 40);

			iSetColor(50, 40, 40);
			iRectangle(25, 645, 110, 40);
			iText(35, 655, "Back", GLUT_BITMAP_HELVETICA_18);
			if (area != 4 && area!=9){
			//point show
			iSetColor(200, 180, 100);
			iFilledRectangle(1030, 650, 140, 40);

			iSetColor(255, 230, 170);
			iFilledRectangle(1035, 645, 130, 40);

			iSetColor(50, 40, 40);
			iRectangle(1035, 645, 130, 40);
			//iText(1045, 655, "Points : ", GLUT_BITMAP_HELVETICA_18);

			char textPoint[50];
			sprintf_s(textPoint, "Pens : %d", points);  // convert int -> string

			iText(1045, 655, textPoint, GLUT_BITMAP_HELVETICA_18);

			//health show
			iSetColor(200, 180, 100);
			iFilledRectangle(1030, 600, 140, 40);

			iSetColor(255, 230, 170);
			iFilledRectangle(1035, 595, 130, 40);

			iSetColor(50, 40, 40);
			iRectangle(1035, 645, 100, 40);
			//iText(1045, 655, "Points : ", GLUT_BITMAP_HELVETICA_18); 

			char texttPoint[50];
			sprintf_s(texttPoint, "Life : %d", life);  // convert int -> string 

			iText(1045, 610, texttPoint, GLUT_BITMAP_HELVETICA_18);





			if (ov)
			{
				if (ov) // life <= 0 
				{
					int boxWidth = 300;
					int boxHeight = 100;
					int boxX = (1200 - boxWidth) / 2; // center horizontally 
					int boxY = (700 - boxHeight) / 2;  // center vertically 

					// Outer rectangle (same as life/pen box) 
					iSetColor(200, 180, 100);
					iFilledRectangle(boxX, boxY, boxWidth, boxHeight);

					// Inner rectangle 
					iSetColor(255, 230, 170);
					iFilledRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight - 10);

					// Border 
					iSetColor(50, 40, 40);
					iRectangle(boxX + 5, boxY + 5, boxWidth - 10, boxHeight -
						10);

					// Text in the middle of the box 
					iSetColor(50, 40, 40); // dark text 
					iText(boxX + 80, boxY + 40, "GAME OVER",
						GLUT_BITMAP_HELVETICA_18);
				}



			}
			if (kolom)
				iShowImage(penx, peny, 60, 30, verimg);
		}
		if (area == 5 || area == 6 || area == 7 || area == 8)
		{
			iSetColor(200, 180, 100);
			iFilledRectangle(20, 600, 170, 40);

			iSetColor(255, 230, 170);
			iFilledRectangle(25, 595, 160, 40);

			iSetColor(50, 40, 40);
			iRectangle(25, 595, 160, 40);


			char textPoin[50];
			sprintf_s(textPoin, "Project Points : %d", prpoint);

			iText(30, 605, textPoin, GLUT_BITMAP_HELVETICA_18);
		}

	}
}



void iMouseMove(int mx, int my)
{

}

void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (screen == -3) {
			//enroll
			if (mx >= 520 && mx <= 680 && my >= 340 && my <= 400) {
				screen = 0;
			}
			//controls btn
			else if (mx >= 520 && mx <= 680 && my >= 260 && my <= 320) {
				screen = -2;
			}
			//credits btn
			else if (mx >= 520 && mx <= 680 && my >= 180 && my <= 240) {
				screen = -1;
			}
			//exit btn
			else if (mx >= 520 && mx <= 680 && my >= 100 && my <= 160) {
				exit(0);
			}


		}
		else if (screen == -1 || screen == -2) {
			// back btn
			if (mx >= 50 && mx <= 170 && my >= 50 && my <= 90) {
				screen = -3;
			}
		}

		if (mx >= backButtonX && mx <= backButtonX + backButtonW &&
			my >= backButtonY && my <= backButtonY + backButtonH)
		{
			screen = -3;
		}


	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void gametimer() {
	if (ov){
		gameOverTimer--;
		if (gameOverTimer <= 0) {
			screen = -3;
		}
	}
}
void quizcollision()
{
	if (kolom && ct){
		if (penx<quizx + x + 190 &&
			penx + 60>quizx + x && peny<quizy + 250 &&
			peny + 30>quizy){
			ct = false;
			kolom = false;

		}
	}
}
void playcollision(){
	if (ct && playx<quizx + x + 190 &&
		playx + 120>quizx + x &&
		playy<quizy + 250 &&
		playy + 270>quizy)
	{
		playx = playx - 100;
		playy = gy;
		life--;
		if (life <= 0){
			ov = true;
			gameOverTimer = 100;
		}
	}
}

void salamsho()
{
	if (!salamTriggered && playx >= 608 && playx <= 808)
	{
		salam = true;
		salamtimer = 150;
		points++;
		salamTriggered = true;
	}
}



// Special Keys:
// GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
// GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT

void fixedUpdate()
{
	int jumpspd = jump ? 5 : 3;
	move = false;
	salamsho();
	if (salamtimer > 0) {
		salamtimer--;
		if (salamtimer == 0) {
			salam = false;
		}
	}

	if (isKeyPressed('m') && !keyp)
	{
		tm = 200;
		if (screen < 3)
		{
			screen++;
			keyp = true;
		}
		if (area == 4)
		{
			xx = 200;
		}
	}
	if (keyp)
	{
		tm--;
		if (tm <= 0)
			keyp = false;
	}
	//----------

	if (isKeyPressed(' ') && !attacking)
	{
		if (!space){
			if (points > 0 && !kolom){
				attacking = true;
				kolom = true;
				attacktimer = 20;
				penx = playx + 100;
				peny = playy + 180;
				points--;
			}
			space = true;
		}
		else
			space = false;

	}
	if (kolom)
	{
		penx += 7;
		if (penx > 1800)
			kolom = false;
		quizcollision();
	}
	if (attacking)
	{
		attacktimer--;
		if (attacktimer <= 0)
			attacking = false;

	}

	//---------
	if ((isKeyPressed('w') || isSpecialKeyPressed(GLUT_KEY_UP)) && !jump)
	{
		jump = true;
		vel = spd;
		playcollision();
	}
	if (isKeyPressed('a') || isSpecialKeyPressed(GLUT_KEY_LEFT))
	{
		x += jumpspd;
		playx -= 1;
		if (playx <= -10)
			playx = -10;
		if (x > 0) {
			x = 0;
			playx -= 3;
		}
		if (xx > 0)
		{
			x = -1800;
			xx--;
			playx -= 3;
		}


		//------
		if (x <= -1650 && (area == 3 || area==8)){
			xx = -50;
			x = -1800;
			playx -= 2;

		}
		if (x <= -1600 && (area == 1 || area==6)){
			xx = -50;
			x = -1800;
			playx -= 2;

		}
		//-----------added



		//----added
		//----
		playcollision();
		move = true;
	}
	if (isKeyPressed('s') || isSpecialKeyPressed(GLUT_KEY_DOWN))
	{

	}

	if (isKeyPressed('d') || isSpecialKeyPressed(GLUT_KEY_RIGHT))
	{
		x -= jumpspd;
		playx += 1;
		if (x <= -1800)
		{
			x = -1800;
			playx += 3;
			xx++;
		}

		if (xx >= 200)
		{
			obsX = 0;
			playx = 10;
			x = 0;
			area++;
			if (area == 1){
				bgImage = iLoadImage("library.png");
				ct = true;
				ov = false;
				if (life < 5)
					life = life + 1;
				//----------------------------------

				//------------------------------
			}
			if (area == 2){
				salam = false;
				salamTriggered = false;
				bgImage = iLoadImage("redx.png");
				ct = true;
				ov = false;
				if (life < 5)
					life = life + 1;
			}
			if (area == 3){
				
				bgImage = iLoadImage("canteen.png");
				ov = false;
				if (life < 5)
					life = life + 1;
			}

			if (area == 5)
			{
				bgImage = iLoadImage("class.png");
				CNT = 0;
				prcnt = 0;
				ct = true;
				ov = false;
				points = 0;
				life = 5;

			}
			if (area == 6)
			{
				bgImage = iLoadImage("shiri.png");
				CNT = 0;
				prcnt = 0;
				ct = true;
				ov = false;
				if (life < 5)
					life = life + 1;
			}
			if (area == 7)
			{
				bgImage = iLoadImage("coridor.png");
				CNT = 0;
				prcnt = 0;
				ct = true;
				ov = false;
				if (life < 5)
					life = life + 1;
			}
			if (area == 8)
			{
				bgImage = iLoadImage("lalit.png");
				if(life < 5)
					life = life + 1;
			}
			xx = 0;

			obstacle();
		}
		playcollision();

		move = true;
	}
	if (jump) {
		playy += vel;
		vel -= grvt;

		if (playy <= gy) {
			playy = gy;
			jump = false;
			vel = 0;
		}
		playcollision();
	}


}

void movement() {
	if (move)
		cur_frame = (cur_frame + 1) % 16;
	else
		cur_frame = 0;

}

void obstacle(){
	int randomX = (rand() % 800);
	int randomY = (rand() % 300) + 30;

	if (randomX < 500){

		obsX = obsX + 500;
		obsY = randomY;
	}
	else {

		obsX = obsX + 800;
		obsY = randomY;

	}


}


//final monster function ddeclare
void finalMonsterAttackMove() {
	finalMonsterAttacking = true;

	if (area == 3 && x == -1800) {  // only in last background, when fixed
		if (finalMonsterAttacking) {
			monsterMove = finalMonsterAttack;

			// Throw paper when attack starts
			if (!isPaperThrown && monsterAlive) {
				isPaperThrown = true;
				paperX = finalMonsX + x;                  // start at monster X
				paperY = finalMonsY + finalMonsHeight / 2;  // middle of monster
			}

			finalMonsterAttacking = false;
		}
	}


	//mini monster work
	miniMonsterAttacking = true;

	if (area == 1 && x == -1800) {
		if (miniMonsterAttacking) {
			minimonsterMove = miniMonsterAttack;


			if (!isPaperThrown && minimonsterAlive) {
				isPaperThrown = true;
				paperX = miniMonsX + x;
				paperY = miniMonsY + miniMonsHeight / 2;
			}

			miniMonsterAttacking = false;
		}
	}
	//second final
	secondfinalMonsterAttacking = true;

	if (area == 8 && x == -1800) {
		if (secondfinalMonsterAttacking) {
			secondfinalmonsterMove = secondfinalMonsterAttack;


			if (!isPaperThrown && secondfinalmonsterAlive) {
				isPaperThrown = true;
				paperX = secondfinalMonsX + x;
				paperY = secondfinalMonsY + secondfinalMonsHeight / 2;
			}

			secondfinalMonsterAttacking = false;
		}
	}
//second mini
	secondminiMonsterAttacking = true;

	if (area == 6 && x == -1800) {
		if (secondminiMonsterAttacking) {
			secondminimonsterMove = secondminiMonsterAttack;


			if (!isPaperThrown && secondminimonsterAlive) {
				isPaperThrown = true;
				paperX = secondminiMonsX + x;
				paperY = secondminiMonsY + secondminiMonsHeight / 2;
			}

			secondminiMonsterAttacking = false;
		}
	}

}


void finalMonsterStandMove(){
	finalMonsterAttacking = false;  // flip between true/false

	if (area == 3 && x == -1800) {  // only in last background, when fixed
		if (!finalMonsterAttacking){
			monsterMove = finalMonsterStand;
			finalMonsterAttacking = true;
		}
	}

}


void movePaper() {
	if (isPaperThrown && monsterAlive && area == 3) {
		paperX -= paperSpeed;   // move left

		if (paperX < 0) {       // out of screen
			isPaperThrown = false;
		}
	}

	//mini monster work
	if (isPaperThrown && minimonsterAlive && area == 1) {
		paperX -= minipaperSpeed;   // move left

		if (paperX < 0) {       // out of screen
			isPaperThrown = false;
		}
	}
	if (isPaperThrown && secondfinalmonsterAlive && area == 8) {
		paperX -= minipaperSpeed;   // move left

		if (paperX < 0) {       // out of screen
			isPaperThrown = false;
		}
	}

	//secondmini monster work
	if (isPaperThrown && secondminimonsterAlive && area == 6) {
		paperX -= minipaperSpeed;   // move left

		if (paperX < 0) {       // out of screen
			isPaperThrown = false;
		}
	}

}



void finalMonsterJump() {
	if (area == 3 && x == -1800) {   // only last background
		if (!isfinalMonsterJump) {
			isfinalMonsterJump = true;
			finalMonsJumpSpd = 25;   // reset jump speed
		}
	}

	if (isfinalMonsterJump) {
		finalMonsY += finalMonsJumpSpd;
		int pr = finalMonsY;
		//printf("%d\n", finalMonsX);
		//printf("%d\n", finalMonsY);
		finalMonsJumpSpd -= 2;   // gravity effect

		if (finalMonsY <= 20) {   // ground level
			finalMonsY = 20;
			isfinalMonsterJump = false;   // finished jump
		}
	}

	//mini monster jump
	if (area == 1 && x == -1800) {   // only last background
		if (!isminiMonsterJump) {
			isminiMonsterJump = true;
			miniMonsJumpSpd = 25;   // reset jump speed
		}
	}

	if (isminiMonsterJump) {
		miniMonsY += miniMonsJumpSpd;
		int pr = miniMonsY;
		miniMonsJumpSpd -= 2;   // gravity effect

		if (miniMonsY <= 20) {   // ground level
			miniMonsY = 20;
			isminiMonsterJump = false;   // finished jump
		}
	}
	//second final
	if (area == 8 && x == -1800) {   // only last background
		if (!issecondfinalMonsterJump) {
			issecondfinalMonsterJump = true;
			secondfinalMonsJumpSpd = 25;   // reset jump speed
		}
	}

	if (issecondfinalMonsterJump) {
		secondfinalMonsY += secondfinalMonsJumpSpd;
		int pr = secondfinalMonsY;
		secondfinalMonsJumpSpd -= 2;   // gravity effect

		if (secondfinalMonsY <= 20) {   // ground level
			secondfinalMonsY = 20;
			issecondfinalMonsterJump = false;   // finished jump
		}
	}


	//secondmini monster jump
	if (area == 6 && x == -1800) {   // only last background
		if (!issecondminiMonsterJump) {
			issecondminiMonsterJump = true;
			secondminiMonsJumpSpd = 25;   // reset jump speed
		}
	}

	if (issecondminiMonsterJump) {
		secondminiMonsY += secondminiMonsJumpSpd;
		int pr = secondminiMonsY;
		secondminiMonsJumpSpd -= 2;   // gravity effect

		if (secondminiMonsY <= 20) {   // ground level
			secondminiMonsY = 20;
			issecondminiMonsterJump = false;   // finished jump
		}
	}

}


void checkPaperCollision() {
	if (isPaperThrown && !ov) {
		if (playx < paperX + 30 &&        // paper width ~50
			playx + 120 > paperX &&       // player width ~220
			playy < paperY + 30 &&        // paper height ~50
			playy + 230 > paperY - 20) {       // player height ~270

			life--;    // lose 1 health
			isPaperThrown = false; // remove paper after hit

			if (life <= 0){
				ov = true;
				gameOverTimer = 100;
			}

		}
	}
}

void checkPenMonsterCollison(){
	if (playx < obsX + obsWidth + x - 100 &&
		playx + 120 > obsX + x &&
		playy < obsY + obsHeight &&
		playy + 270 > obsY){

		points++;
		prcnt++;
		obstacle();
	}
	if (area == 6 && secondminimonsterAlive) {

		if (playx + 120 > secondminiMonsX + x &&
			playx < secondminiMonsX + secondminiMonsWidth + x) {

			playx = playx - 150;
			life--;// clamp to boundary
		}
	}
	if (area == 8 && secondfinalmonsterAlive) {

		if (playx + 120 > secondfinalMonsX + x &&
			playx < secondfinalMonsX + secondfinalMonsWidth + x) {

			playx = playx - 150;
			life--;// clamp to boundary
		}
	}

	if (area == 1 && minimonsterAlive) {

		if (playx + 120 > miniMonsX + x &&
			playx < miniMonsX + miniMonsWidth + x) {

			playx = playx - 150;
			life--;// clamp to boundary
		}
	}
	if (area == 3 && monsterAlive) {

		if (playx + 120 > finalMonsX + x &&
			playx < finalMonsX + finalMonsWidth + x) {

			playx = playx - 150; 
			life--;// clamp to boundary
		}
	}
	if (monsterAlive && area == 3) {

		if (penx + 60 >(finalMonsX + x) &&
			penx  < (finalMonsX + finalMonsWidth + x) &&
			peny + 30 > finalMonsY &&
			peny < finalMonsY + finalMonsHeight)
		{
			monsterHealth = monsterHealth - 1;   // monster hit by pen!

			//remove pen after hit
			kolom = false;
			penx = -2000;

			if (monsterHealth <= 0) {
				monsterAlive = false;  // monster vanishes
				paperY = 1000;
				isPaperThrown = false;

			}
		}

	}

	//mini monster work
	if (minimonsterAlive && area == 1) {

		if (penx + 60 > (miniMonsX + x) &&
			penx  < (miniMonsX + miniMonsWidth + x) &&
			peny + 30 > miniMonsY &&
			peny < miniMonsY + miniMonsHeight)
		{
			minimonsterHealth = minimonsterHealth - 1;   // monster hit by pen!

			//remove pen after hit
			kolom = false;
			penx = -2000;

			if (minimonsterHealth <= 0) {
				minimonsterAlive = false;  // monster vanishes
				paperY = 1000;
				isPaperThrown = false;
			}
		}

	}
	if (secondfinalmonsterAlive && area == 8) {

		if (penx + 60 > (secondfinalMonsX + x) &&
			penx  < (secondfinalMonsX + secondfinalMonsWidth + x) &&
			peny + 30 > secondfinalMonsY &&
			peny < secondfinalMonsY + secondfinalMonsHeight)
		{
			secondfinalmonsterHealth = secondfinalmonsterHealth - 1;   // monster hit by pen!

			//remove pen after hit
			kolom = false;
			penx = -2000;

			if (secondfinalmonsterHealth <= 0) {
				secondfinalmonsterAlive = false;  // monster vanishes
				paperY = 1000;
				isPaperThrown = false;
			}
		}

	}


	//secondmini monster work
	if (secondminimonsterAlive && area == 6) {

		if (penx + 60 > (secondminiMonsX + x) &&
			penx  < (secondminiMonsX + secondminiMonsWidth + x) &&
			peny + 30 > secondminiMonsY &&
			peny < secondminiMonsY + secondminiMonsHeight)
		{
			secondminimonsterHealth = secondminimonsterHealth - 1;   // monster hit by pen!

			//remove pen after hit
			kolom = false;
			penx = -2000;

			if (secondminimonsterHealth <= 0) {
				secondminimonsterAlive = false;  // monster vanishes
				paperY = 1000;
				isPaperThrown = false;
			}
		}

	}


}


int main()
{
	///srand((unsigned)time(NULL));
	image = iLoadImage("menu.png"); // background image

	iInitialize(1200, 700, "Debugging AUST");
	playerpic();
	iSetTimer(10, fixedUpdate);
	iSetTimer(100, movement);
	iSetTimer(20, proj);
	obstacle();
	iSetTimer(10, gametimer);
	iSetTimer(1000, finalMonsterAttackMove);   // change every 0.5 sec (500 ms)
	iSetTimer(300, finalMonsterStandMove);   // change every 0.5 sec (500 ms)
	iSetTimer(40, finalMonsterJump);   // update jump movement
	iSetTimer(30, movePaper);
	iSetTimer(20, checkPaperCollision);
	iSetTimer(10, checkPenMonsterCollison);


	//loading images

	iStart();
	return 0;
}