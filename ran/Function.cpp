
#include "Header.h"

void FillBackground(SDL_Renderer* renderer)
{
	//tô nền
	SDL_SetRenderDrawColor(renderer, 255, 50, 80, 0);// Select the color for drawing. It is set to red here.
	SDL_RenderClear(renderer);// Clear the entire screen to our selected color.
}
void DropFood(SDL_Renderer* renderer, SDL_Rect rectangle)
{
	SDL_SetRenderDrawColor(renderer, 30, 25, 255, 100);
	SDL_RenderFillRect(renderer, &rectangle);
	SDL_RenderPresent(renderer);
}

void GameMode1()
{
	//Khởi tạo thư viện(Khởi động)
	SDL_Init(SDL_INIT_EVERYTHING);
	srand((unsigned int)time(NULL));
	SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);	//CREATE SDL WINDOW
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	// We must call SDL_CreateRenderer in order for draw calls to affect this window.

	SDL_Event e;
	Snake snake;
	SDL_Rect food;
	food.w = 20;
	food.h = 20;
	food.x = rand() % (SCREEN_WIDTH / 20)* 20;
	food.y = rand() % (SCREEN_HEIGHT / 20)* 20;
	bool running = true;
	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) {
				running = false;
			}
			else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_w: case SDLK_UP:
					snake.setDirection(0, -1);
					FillBackground(renderer);//tô nền
					SDL_Delay(100);
					snake.Move();
					snake.ShowSnake(renderer);
                    if (snake.EatBody(snake))
                    {
                       running = false;
                    }
					if (snake.isEat(food))
					{
						snake.GrowUp();
						food.x = rand() % (SCREEN_WIDTH / 20)* 20;
						food.y = rand() % (SCREEN_HEIGHT / 20)* 20;
						DropFood(renderer, food);
					}
					DropFood(renderer, food);
					break;
				case SDLK_s: case SDLK_DOWN:
					snake.setDirection(0, 1);
					FillBackground(renderer);//tô nền
					SDL_Delay(100);
					snake.Move();
					snake.ShowSnake(renderer);
					if (snake.EatBody(snake))
                    {
                       running = false;
                    }
					if (snake.isEat(food))
					{
						snake.GrowUp();
						food.x = rand() % (SCREEN_WIDTH / 20)* 20;
						food.y = rand() % (SCREEN_HEIGHT / 20)* 20;
						DropFood(renderer, food);
					}
					DropFood(renderer, food);
					break;
				case SDLK_a: case SDLK_LEFT:
					snake.setDirection(-1, 0);
					FillBackground(renderer);//tô nền
					SDL_Delay(100);
					snake.Move();
					snake.ShowSnake(renderer);
					if (snake.EatBody(snake))
                    {
                       running = false;
                    }
					if (snake.isEat(food))
					{
						snake.GrowUp();
						food.x = rand() % (SCREEN_WIDTH / 20)* 20;
						food.y = rand() % (SCREEN_HEIGHT / 20)* 20;
						DropFood(renderer, food);
					}
					DropFood(renderer, food);
					break;
				case SDLK_d: case SDLK_RIGHT:
					snake.setDirection(1, 0);
					FillBackground(renderer);//tô nền
					SDL_Delay(100);
					snake.Move();
					snake.ShowSnake(renderer);
					if (snake.EatBody(snake))
                    {
                       running = false;
                    }
					if (snake.isEat(food))
					{
						snake.GrowUp();
						food.x = rand() % (SCREEN_WIDTH / 20)* 20;
						food.y = rand() % (SCREEN_HEIGHT / 20)* 20;
						DropFood(renderer, food);
					}
					DropFood(renderer, food);
					break;
				}
			}
		}

		FillBackground(renderer);//tô nền
		SDL_Delay(100);
		snake.Move();
		snake.ShowSnake(renderer);
		if (snake.EatBody(snake))
        {
            running = false;
        }
		if (snake.isEat(food))
		{
			snake.GrowUp();
			food.x = rand() % (SCREEN_WIDTH / 20)* 20;
			food.y = rand() % (SCREEN_HEIGHT / 20)* 20;
			DropFood(renderer, food);
		}
		DropFood(renderer, food);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
