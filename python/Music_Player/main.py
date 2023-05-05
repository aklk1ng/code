import pygame
import os

# 初始化Pygame
pygame.init()

# 设置窗口大小
WIDTH, HEIGHT = 500, 300
win = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Music Player")

# 加载音乐文件
music_folder = "/home/cjh/yt-dlp/music/"
music_files = os.listdir(music_folder)
music_list = []
for file in music_files:
    if file.endswith(".mp3"):
        music_list.append(os.path.join(music_folder, file))

# 设置字体
font = pygame.font.SysFont("comicsans", 20)

# 设置颜色
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# 设置音乐播放器
pygame.mixer.music.set_volume(0.5)
current_music = 0
pygame.mixer.music.load(music_list[current_music])
pygame.mixer.music.play()

# 循环播放
playing = True
while playing:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            playing = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                if pygame.mixer.music.get_busy():
                    pygame.mixer.music.pause()
                else:
                    pygame.mixer.music.unpause()
            elif event.key == pygame.K_LEFT:
                pygame.mixer.music.rewind()
            elif event.key == pygame.K_RIGHT:
                current_music = (current_music + 1) % len(music_list)
                pygame.mixer.music.load(music_list[current_music])
                pygame.mixer.music.play()
    win.fill(WHITE)
    song_name = music_list[current_music].split("/")[-1]
    text = font.render(song_name, True, BLACK)
    win.blit(text, (50, 50))
    pygame.display.update()

# 退出程序
pygame.quit()
