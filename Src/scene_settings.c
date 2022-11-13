#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <math.h>
#include "scene_menu_object.h"
#include "scene_settings.h"
#include "scene_game.h"
#include "scene_menu.h"
#include "utility.h"
#include "shared.h"


/* Internal Variables*/
static ALLEGRO_BITMAP* gameTitle = NULL;
static ALLEGRO_SAMPLE_ID menuBGM;
static int gameTitleW;
static int gameTitleH;
static ALLEGRO_BITMAP* gameTitle1 = NULL;
static int gameTitleW1;
static int gameTitleH1;
static ALLEGRO_BITMAP* gameTitle2 = NULL;
static int gameTitleW2;
static int gameTitleH2;
static ALLEGRO_BITMAP* gameTitle3 = NULL;
static int gameTitleW3;
static int gameTitleH3;

static Button go_back;
static Button vol_on;
static Button vol_down;
static Button efvol_on;
static Button efvol_down;
extern float music_volume ;
extern float effect_volume ;
extern ALLEGRO_FONT* menuFont;
static Button ad;
extern int pbt;
extern int eaten_bean_num;
extern int ghost_det_time;//5-50;
extern ebnm;
Scene scene_asettings_create(void);

static void init() {	
    go_back = button_create(715, 20, 70, 70, "Assets/balb.png", "Assets/balbh.png");
	vol_on = button_create(600, 200, 110, 130, "Assets/+.png", "Assets/+h.png");
	vol_down = button_create(350, 190, 110, 130, "Assets/-.png", "Assets/-h.png");
	efvol_on = button_create(600, 450, 110, 130, "Assets/+ef.png", "Assets/+efh.png");
	efvol_down = button_create(350, 440, 110, 130, "Assets/-ef.png", "Assets/-efh.png");
	ad = button_create(30, 20, 110, 110, "Assets/ads.png", "Assets/adsh.png");
	//gameTitle = load_bitmap("Assets/title.png");
	//gameTitleW = al_get_bitmap_width(gameTitle);
	//gameTitleH = al_get_bitmap_height(gameTitle);
	//stop_bgm(menuBGM);
	//menuBGM = play_bgm(themeMusic, music_volume);
	
}
static void on_mouse_move(int a, int mouse_x, int mouse_y, int f) {
	//	[HACKATHON 3-7]
	//	TODO: Update button's status(hovered), and utilize the function `pnt_in_rect`, which you just implemented
	//	Uncomment and fill the code below
	go_back.hovered = pnt_in_rect(mouse_x, mouse_y, go_back.body);
	vol_on.hovered = pnt_in_rect(mouse_x, mouse_y, vol_on.body);
	vol_down.hovered = pnt_in_rect(mouse_x, mouse_y, vol_down.body);
	efvol_on.hovered = pnt_in_rect(mouse_x, mouse_y, efvol_on.body);
	efvol_down.hovered = pnt_in_rect(mouse_x, mouse_y, efvol_down.body);
	ad.hovered = pnt_in_rect(mouse_x, mouse_y, ad.body);
}
static void on_mouse_down() {
	game_log("ssson_mouse_down\n");
	if (go_back.hovered && on_mouse_down)
		game_change_scene(scene_menu_create());
	if (vol_on.hovered && on_mouse_down && (music_volume<=1)) {
		music_volume += 0.1;
		game_log("mvol_%f\n",music_volume);
	}	
	if (vol_down.hovered && on_mouse_down && (music_volume > 0.1)) {
		music_volume -= 0.1;
		game_log("mvol_%f\n",music_volume);
	}
	if (efvol_on.hovered && on_mouse_down && (effect_volume <= 1)) {
		effect_volume += 0.1;
		game_log("efvol_%f\n", effect_volume);
	}
	if (efvol_down.hovered && on_mouse_down && (effect_volume > 0.1)) {
		effect_volume -= 0.1;
		game_log("efvol_%f\n", effect_volume);
	}
	if (ad.hovered && on_mouse_down) {
		game_change_scene(scene_asettings_create());
	}
		

	
}
static void destroy() {
	stop_bgm(menuBGM);

	//al_destroy_bitmap(gameTitle);
	//	[HACKATHON 3-10]
	//	TODO: Destroy button images
	//	Uncomment and fill the code below

	al_destroy_bitmap(go_back.default_img);
	al_destroy_bitmap(go_back.hovered_img);
	al_destroy_bitmap(vol_on.default_img);
	al_destroy_bitmap(vol_on.hovered_img);
	al_destroy_bitmap(vol_down.default_img);
	al_destroy_bitmap(vol_down.hovered_img);
	al_destroy_bitmap(efvol_on.default_img);
	al_destroy_bitmap(efvol_on.hovered_img);
	al_destroy_bitmap(efvol_down.default_img);
	al_destroy_bitmap(efvol_down.hovered_img);
	al_destroy_bitmap(ad.default_img);
	al_destroy_bitmap(ad.hovered_img);
}
static void on_key_down(int keycode) {

	switch (keycode) {
	case ALLEGRO_KEY_ENTER:
		//game_change_scene(scene_main_create());
		break;
	default:
		break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// [HACKATHON 3-9]
// TODO: Create scene_settings.h and scene_settings.c.
// No need to do anything for this part. We've already done it for
// you, so this 2 files is like the default scene template.

// Variables and functions with 'static' prefix at the top level of a
// source file is only accessible in that file ("file scope", also
// known as "internal linkage"). If other files has the same variable
// name, they'll be different variables.

/* Define your static vars / function prototypes below. */

// TODO: More variables and functions that will only be accessed
// inside this scene. They should all have the 'static' prefix.
static void draw(void ){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		SCREEN_H - 150,
		ALLEGRO_ALIGN_CENTER,
		"Settings"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		750,
		100,
		ALLEGRO_ALIGN_CENTER,
		"Menu"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		95,
		145,
		ALLEGRO_ALIGN_CENTER,
		"Advance"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		200,
		270,
		ALLEGRO_ALIGN_CENTER,
		"Music Volume:"
	);
	al_draw_textf(
		menuFont,
		al_map_rgb(255, 255, 255),
		510,
		270,
		ALLEGRO_ALIGN_CENTER,
		"%d",(int)(10*(music_volume))
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		200,
		520,
		ALLEGRO_ALIGN_CENTER,
		"Effect Volume:"
	);
	al_draw_textf(
		menuFont,
		al_map_rgb(255, 255, 255),
		510,
		520,
		ALLEGRO_ALIGN_CENTER,
		"%d", (int)(10 * (effect_volume))
	);
	drawButton(go_back);
	drawButton(vol_on);
	drawButton(vol_down);
	drawButton(efvol_on);
	drawButton(efvol_down);
	drawButton(ad);
}
// The only function that is shared across files.
Scene scene_settings_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Settings";
	scene.draw = &draw;
	scene.initialize = &init;
	scene.destroy = &destroy;
	scene.on_key_down = &on_key_down;
	scene.on_mouse_move = &on_mouse_move;
	scene.on_mouse_down = &on_mouse_down;
	// [HACKATHON 3-9]
	// TODO: Register on_mouse_down.
	// Uncomment the code below.
	// TODO: Register more event callback functions such as keyboard, mouse, ...

	return scene;
}
//////
//////
//aset
static Button basic;
static Button pbt_plus;
static Button pbt_minus;
static Button ebn_plus;
static Button ebn_minus;
static Button gdt_plus;
static Button gdt_minus;

static void ainit() {
	basic = button_create(650, 20,135, 135, "Assets/sp.png", "Assets/sph.png");
	pbt_plus = button_create(550, 200, 70, 120, "Assets/uarr.png", "Assets/uarrh.png");
	pbt_minus = button_create(230, 200, 70, 120, "Assets/darr.png", "Assets/darrh.png");
	ebn_plus = button_create(550, 420, 70, 120, "Assets/uarr1.png", "Assets/uarrh1.png");
	ebn_minus = button_create(230, 420, 70, 120, "Assets/darr1.png", "Assets/darrh1.png");
	gdt_plus = button_create(550, 640, 70, 120, "Assets/uarr2.png", "Assets/uarrh2.png");
	gdt_minus = button_create(230, 640, 70, 120, "Assets/darr2.png", "Assets/darrh2.png");
	//gameTitle = load_bitmap("Assets/title.png");
	//gameTitleW = al_get_bitmap_width(gameTitle);
	//gameTitleH = al_get_bitmap_height(gameTitle);
	//stop_bgm(menuBGM);
	//menuBGM = play_bgm(themeMusic, music_volume);
	gameTitle1 = load_bitmap("Assets/pbth.png");
	gameTitleW1 = al_get_bitmap_width(gameTitle1);
	gameTitleH1 = al_get_bitmap_height(gameTitle1);
	gameTitle2 = load_bitmap("Assets/ebnp.png");
	gameTitleW2 = al_get_bitmap_width(gameTitle2);
	gameTitleH2 = al_get_bitmap_height(gameTitle2);
	gameTitle3 = load_bitmap("Assets/gdtp.png");
	gameTitleW3 = al_get_bitmap_width(gameTitle3);
	gameTitleH3 = al_get_bitmap_height(gameTitle3);
}
static void aon_mouse_move(int a, int mouse_x, int mouse_y, int f) {
	//	[HACKATHON 3-7]
	//	TODO: Update button's status(hovered), and utilize the function `pnt_in_rect`, which you just implemented
	//	Uncomment and fill the code below
	basic.hovered = pnt_in_rect(mouse_x, mouse_y, basic.body);
	pbt_plus.hovered = pnt_in_rect(mouse_x, mouse_y, pbt_plus.body);
	pbt_minus.hovered = pnt_in_rect(mouse_x, mouse_y, pbt_minus.body);
	ebn_plus.hovered = pnt_in_rect(mouse_x, mouse_y, ebn_plus.body);
	ebn_minus.hovered = pnt_in_rect(mouse_x, mouse_y, ebn_minus.body);
	gdt_plus.hovered = pnt_in_rect(mouse_x, mouse_y, gdt_plus.body);
	gdt_minus.hovered = pnt_in_rect(mouse_x, mouse_y, gdt_minus.body);
}
static void aon_mouse_down() {
	game_log("ssson_mouse_down\n");
	if (basic.hovered && on_mouse_down)
		game_change_scene(scene_settings_create());
	if (pbt_plus.hovered && on_mouse_down && (pbt <= 4500)) {
		pbt += 500;
		game_log("pbt_%f\n", pbt);
	}
	if (pbt_minus.hovered && on_mouse_down && (pbt >= 1000)) {
		pbt -= 500;
		game_log("pbt_%f\n", pbt);
	}
	if (ebn_plus.hovered && on_mouse_down && (eaten_bean_num < 20*(ebnm))) {
		eaten_bean_num += 20;
		game_log("ebn_%f\n", eaten_bean_num);
	}
	if (ebn_minus.hovered && on_mouse_down && (eaten_bean_num >= 40)) {
		eaten_bean_num -= 20;
		game_log("ebn_%f\n", eaten_bean_num);
	}
	if (gdt_plus.hovered && on_mouse_down && (ghost_det_time <= 45)) {
		ghost_det_time += 5;
		game_log("gdt_%f\n", ghost_det_time);
	}
	if (gdt_minus.hovered && on_mouse_down && (ghost_det_time >= 10)) {
		ghost_det_time -= 5;
		game_log("gdt_%f\n", ghost_det_time);
	}



}
static void adestroy() {
	

	al_destroy_bitmap(basic.default_img);
	al_destroy_bitmap(basic.hovered_img);
	al_destroy_bitmap(pbt_minus.default_img);
	al_destroy_bitmap(pbt_minus.hovered_img);
	al_destroy_bitmap(pbt_plus.default_img);
	al_destroy_bitmap(pbt_plus.hovered_img);
	al_destroy_bitmap(ebn_plus.default_img);
	al_destroy_bitmap(ebn_plus.hovered_img);
	al_destroy_bitmap(ebn_minus.default_img);
	al_destroy_bitmap(ebn_minus.hovered_img);
	al_destroy_bitmap(gdt_minus.default_img);
	al_destroy_bitmap(gdt_minus.hovered_img);
	al_destroy_bitmap(gdt_plus.default_img);
	al_destroy_bitmap(gdt_plus.hovered_img);

	al_destroy_bitmap(gameTitle1);
	al_destroy_bitmap(gameTitle2);
	al_destroy_bitmap(gameTitle3);

}
static void aon_key_down(int keycode) {

	switch (keycode) {
	case ALLEGRO_KEY_ENTER:
		//game_change_scene(scene_main_create());
		break;
	default:
		break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// [HACKATHON 3-9]
// TODO: Create scene_settings.h and scene_settings.c.
// No need to do anything for this part. We've already done it for
// you, so this 2 files is like the default scene template.

// Variables and functions with 'static' prefix at the top level of a
// source file is only accessible in that file ("file scope", also
// known as "internal linkage"). If other files has the same variable
// name, they'll be different variables.


static void adraw(void) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		70,
		10,
		ALLEGRO_ALIGN_CENTER,
		"Settings"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		720,
		180,
		ALLEGRO_ALIGN_CENTER,
		"Basic"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		110,
		250,
		ALLEGRO_ALIGN_CENTER,
		"Power Bean"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		105,
		300,
		ALLEGRO_ALIGN_CENTER,
		"Time"
	);
	al_draw_textf(
		menuFont,
		al_map_rgb(255, 255, 255),
		700,
		340,
		ALLEGRO_ALIGN_CENTER,
		"LEVEL : %d", (int)(pbt/500)
	);
	float pbtf = pbt;
	float pa1 = (pbtf/5000);
	al_draw_scaled_bitmap(
		gameTitle1,
		0, 0,
		(float)gameTitleW1, (float)gameTitleH1, 428-(float)(gameTitleW1 * (0.2 + pa1)*0.5), 270-(float)(gameTitleH1 * (0.2 + pa1)*0.5),
		(float)(gameTitleW1*(0.2+pa1)), (float)(gameTitleH1*(0.2 + pa1)),0);
	float ebnf = eaten_bean_num;
	float pa2 = (ebnf /400);
	al_draw_scaled_bitmap(
		gameTitle2,
		0, 0,
		(float)gameTitleW2, (float)gameTitleH2, 428 - (float)(gameTitleW2 * (0.1+pa2) * 0.5), 490 - (float)(gameTitleH2 * (0.1 + pa2) * 0.5),
		(float)(gameTitleW2 * (0.1 + pa2)), (float)(gameTitleH2 * (0.1 + pa2)), 0);
	float gdtf = ghost_det_time;
	float pa3 = (gdtf / 50);
	al_draw_scaled_bitmap(
		gameTitle3,
		0, 0,
		(float)gameTitleW3, (float)gameTitleH3, 428 - (float)(gameTitleW3 * (0.1+pa3) * 0.5), 700 - (float)(gameTitleH3 * (0.1+pa3) * 0.5),
		(float)(gameTitleW3 * (0.1 + pa3)), (float)(gameTitleH3 * (0.1 + pa3)), 0);
	
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		112,
		445,
		ALLEGRO_ALIGN_CENTER,
		"Points"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		112,
		495,
		ALLEGRO_ALIGN_CENTER,
		"Winning"
	);
	al_draw_textf(
		menuFont,
		al_map_rgb(255, 255, 255),
		700,
		540,
		ALLEGRO_ALIGN_CENTER,
		"LEVEL : %d", (int)(eaten_bean_num/20)
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		110,
		665,
		ALLEGRO_ALIGN_CENTER,
		"Ghost"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		105,
		715,
		ALLEGRO_ALIGN_CENTER,
		"Jail Time"
	);
	al_draw_textf(
		menuFont,
		al_map_rgb(255, 255, 255),
		700,
		760,
		ALLEGRO_ALIGN_CENTER,
		"LEVEL : %d", (int)(ghost_det_time/5)
	);
	drawButton(basic);
	drawButton(pbt_minus);
	drawButton(pbt_plus);
	drawButton(ebn_plus);
	drawButton(ebn_minus);
	drawButton(gdt_plus);
	drawButton(gdt_minus);
}
// The only function that is shared across files.
Scene scene_asettings_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Settings";
	scene.draw = &adraw;
	scene.initialize = &ainit;
	scene.destroy = &adestroy;
	scene.on_key_down = &aon_key_down;
	scene.on_mouse_move = &aon_mouse_move;
	scene.on_mouse_down = &aon_mouse_down;
	// [HACKATHON 3-9]
	// TODO: Register on_mouse_down.
	// Uncomment the code below.
	// TODO: Register more event callback functions such as keyboard, mouse, ...

	return scene;
}
