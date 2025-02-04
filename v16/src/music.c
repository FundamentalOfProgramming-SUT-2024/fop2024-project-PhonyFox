#include "rogue.h"

Mix_Music *current_music = NULL;

void play_or_replace_music(const char *musicFile) {
    if (strcmp(musicFile, "N") == 0) {
        stop_music();
        return;
    }
    if (Mix_PlayingMusic() == 0) {
        Mix_Music *bgMusic = Mix_LoadMUS(musicFile);
        Mix_PlayMusic(bgMusic, -1);
        Mix_VolumeMusic(32);
    } else {
        Mix_HaltMusic(); 
        Mix_Music *bgMusic = Mix_LoadMUS(musicFile);
        Mix_PlayMusic(bgMusic, -1); 
        Mix_VolumeMusic(32);
    }
}

void stop_music() {
    Mix_HaltMusic();
}

void pause_music() {
    if (Mix_PlayingMusic()) {
        Mix_PauseMusic();
    }
}

void resume_music() {
    if (Mix_PausedMusic()) {
        Mix_ResumeMusic();
    }
}

void play_effect1() {
    // Check if the channel is currently playing
    if (!Mix_Playing(1)) {
        Mix_Chunk *effect1 = Mix_LoadWAV("walking.mp3");
        if (effect1) {
            Mix_PlayChannel(1, effect1, 0);
        }
    }
}

void play_effect2() {
    // Check if the channel is currently playing
    if (!Mix_Playing(2)) {
        Mix_Chunk *effect1 = Mix_LoadWAV("bleeding.mp3");
        if (effect1) {
            Mix_PlayChannel(2, effect1, 0);
        }
    }
}

void play_effect3() {
    // Check if the channel is currently playing
    if (!Mix_Playing(2)) {
        Mix_Chunk *effect1 = Mix_LoadWAV("collect.mp3");
        if (effect1) {
            Mix_PlayChannel(2, effect1, 0);
        }
    }
}

void play_effect4() {
    // Check if the channel is currently playing
    if (!Mix_Playing(2)) {
        Mix_Chunk *effect1 = Mix_LoadWAV("coin.mp3");
        if (effect1) {
            Mix_PlayChannel(2, effect1, 0);
        }
    }
}



void play_effect_newRoom() {
    Mix_Chunk *effect2 = Mix_LoadWAV("effect2.mp3");
    Mix_PlayChannel(-1, effect2, 0);
}

void play_effect_die() {
    Mix_Chunk *effect3 = Mix_LoadWAV("die.mp3");
    Mix_PlayChannel(-1, effect3, 0);
}

void play_effect_lose() {
    Mix_Chunk *effect3 = Mix_LoadWAV("gta.mp3");
    Mix_PlayChannel(-1, effect3, 0);
}

void play_effect_win() {
    Mix_Chunk *effect3 = Mix_LoadWAV("success.mp3");
    Mix_PlayChannel(-1, effect3, 0);
}

void play_effect_fight() {
    Mix_Chunk *effect3 = Mix_LoadWAV("sword.mp3");
    Mix_PlayChannel(-1, effect3, 0);
}

void play_effect_heart() {
    Mix_Chunk *effect3 = Mix_LoadWAV("heart.mp3");
    Mix_PlayChannel(-1, effect3, 0);
}

void play_effect_horror() {
    Mix_Chunk *effect3 = Mix_LoadWAV("horror.mp3");
    Mix_PlayChannel(-1, effect3, 0);
}


// void play_effect1();
// void play_effect_newRoom();
// void play_effect_die();
// void play_effect_lose();
// void play_effect_win();
// void play_effect_fight();
// void play_effect_heart();
// void play_effect_horror();

