import random
import sys

import pygame

speed = 25

# window size
frame_size_x = 1440
frame_size_y = 720

check_errors = pygame.init()
if check_errors[1] > 0:
    print("Error: " + check_errors[1])
else:
    print("Game Successfully Initialized!")

# initialise game window
pygame.display.set_caption("Snake Game")
game_window = pygame.display.set_mode([frame_size_x, frame_size_y])

# colors
black = pygame.Color(0, 0, 0)
white = pygame.Color(255, 255, 255)
red = pygame.Color(255, 0, 0)
green = pygame.Color(0, 255, 0)
blue = pygame.Color(0, 0, 255)

fps_controller = pygame.time.Clock()

# one snake square size
square_size = 30


def init_vars():
    global head_pos, snake_body, food_pos, food_spawn, score, direction
    direction = "right"
    head_pos = [120, 60]
    snake_body = [[120, 60]]
    food_pos = [random.randrange(1, (frame_size_x // square_size)) * square_size,
                random.randrange(1, (frame_size_y // square_size)) * square_size]
    food_spawn = True
    score = 0


init_vars()


def show_score(choice, color, font, size):
    score_font = pygame.font.SysFont(font, size)
    score_surface = score_font.render("Score: " + str(score), True, color)
    score_rect = score_surface.get_rect()
    if choice == 1:
        score_rect.midtop = (frame_size_x / 10, 15)
    else:
        score_rect.midtop = (frame_size_x / 2, frame_size_y / 1.25)

    game_window.blit(score_surface, score_rect)


class Music():

    def __init__(self, fileName):
        self.fileName = fileName
        pygame.mixer.init()
        pygame.mixer.music.load(self.fileName)

    def play(self):
        pygame.mixer.music.play(loops=-1)


music = Music('music/startup.mp3')
music.play()

# game loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if (event.key == pygame.K_UP and direction != "down"):
                direction = "up"
            elif (event.key == pygame.K_DOWN and direction != "up"):
                direction = "down"
            elif (event.key == pygame.K_LEFT and direction != "right"):
                direction = "left"
            elif (event.key == pygame.K_RIGHT and direction != "left"):
                direction = "right"

    if direction == "up":
        head_pos[1] -= square_size
    elif direction == "down":
        head_pos[1] += square_size
    elif direction == "left":
        head_pos[0] -= square_size
    elif direction == "right":
        head_pos[0] += square_size

# boundary processing
    if head_pos[0] < 0:
        head_pos[0] = frame_size_x - square_size
    elif head_pos[0] > frame_size_x - square_size:
        head_pos[0] = 0
    elif head_pos[1] < 0:
        head_pos[1] = frame_size_y - square_size
    elif head_pos[1] > frame_size_x - square_size:
        head_pos[1] = 0

    snake_body.insert(0, list(head_pos))
    if head_pos[0] == food_pos[0] and head_pos[1] == food_pos[1]:
        score += 1
        food_spawn = False
    else:
        snake_body.pop()

# spawn food
    if not food_spawn:
        food_pos = [
          random.randrange(1, (frame_size_x // square_size)) * square_size,
          random.randrange(1, (frame_size_y // square_size)) * square_size
        ]
        food_spawn = True

# GFX
    game_window.fill(black)
    for pos in snake_body:
        pygame.draw.rect(
          game_window, green,
          pygame.Rect(pos[0] + 2, pos[1] + 2, square_size - 2, square_size - 2))

        pygame.draw.rect(game_window, red,
                         pygame.Rect(food_pos[0], food_pos[1], square_size, square_size))

# game over conditions
    for block in snake_body[1:]:
        if head_pos[0] == block[0] and head_pos[1] == block[1]:
            init_vars()

    show_score(1, white, 'cousine', 25)
    pygame.display.update()
    fps_controller.tick(speed)
