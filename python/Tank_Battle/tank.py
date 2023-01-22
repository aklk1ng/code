import sys
import pygame
import time
import random

result = sys.path
for temppath in result:
    print(temppath)
color_bg = pygame.Color(255, 255, 255)
color_textSurface = pygame.Color(255, 0, 0)


class MainGame():
    window = None
    screen_width = 2500
    screen_height = 1700

    TANK_P1 = None
    EnemyTank_list = []
    EnemyTank_count = 3
    Bullet_list = []
    EnemyBullet_list = []
    Wall_list = []

    def __init__(self):
        pass

    # begin the game
    def startGame(self):
        pygame.display.init()
        MainGame.window = pygame.display.set_mode([MainGame.screen_width, MainGame.screen_height])
        self.createMyTank()
        self.createEnemyTank()
        self.createWalls()
        # my window manager will not display the window's tittle
        pygame.display.set_caption("Tank_Battle")
        while True:
            MainGame.window.fill(color_bg)
            self.getEvent()
            # display the text
            MainGame.window.blit(self.getTextSurface("Enemy:%d" % len(MainGame.EnemyTank_list)), (5, 5))
            self.blitWalls()
            # display the tank
            if MainGame.TANK_P1 and MainGame.TANK_P1.live:
                MainGame.TANK_P1.displayTank()
            else:
                del MainGame.TANK_P1
                MainGame.TANK_P1 = None
            self.blitEnemyTank()

            if MainGame.TANK_P1 and not MainGame.TANK_P1.stop:
                MainGame.TANK_P1.move()
                MainGame.TANK_P1.collisionWalls()
                MainGame.TANK_P1.hitEnemyTank()

            self.blitBullet()
            self.blitEnemyBullet()
            time.sleep(0.02)
            # udpate the window
            pygame.display.update()

    def createMyTank(self):
        MainGame.TANK_P1 = MyTank(1100, 1300)
        music = Music('music/startup.mp3')
        music.play()

    def createEnemyTank(self):
        top = 200
        for i in range(MainGame.EnemyTank_count):
            speed = random.randint(5, 8)
            left = random.randint(1, 24)
            eTank = EnemyTank(left * 100, top, speed)
            MainGame.EnemyTank_list.append(eTank)

    def createWalls(self):
        for i in range(1, 5):
            wall = Wall(560 * i, 800)
            MainGame.Wall_list.append(wall)

    def blitWalls(self):
        for wall in MainGame.Wall_list:
            if wall.live:
                wall.displayWall()
            else:
                MainGame.Wall_list.remove(wall)

    def blitEnemyTank(self):
        for eTank in MainGame.EnemyTank_list:
            if eTank.live:
                eTank.displayTank()
                eTank.randMove()
                eTank.collisionWalls()
                if MainGame.TANK_P1 and MainGame.TANK_P1.live:
                    eTank.hitMyTank()
                eBullet = eTank.shot()
                if eBullet:
                    MainGame.EnemyBullet_list.append(eBullet)
            else:
                MainGame.EnemyTank_list.remove(eTank)

    def blitBullet(self):
        for bullet in MainGame.Bullet_list:
            if bullet.live:
                bullet.displatBullet()
                bullet.BulletMove()
                bullet.hitEnemyTank()
                bullet.hitWalls()
            else:
                MainGame.Bullet_list.remove(bullet)

    def blitEnemyBullet(self):
        for eBullet in MainGame.EnemyBullet_list:
            if eBullet.live:
                eBullet.displatBullet()
                eBullet.BulletMove()
                eBullet.hitWalls()
            if MainGame.TANK_P1 and MainGame.TANK_P1.live:
                eBullet.hitMyTank()
            else:
                MainGame.EnemyBullet_list.remove(eBullet)

    def getEvent(self):
        eventList = pygame.event.get()
        for event in eventList:
            # quit
            if event.type == pygame.QUIT:
                self.endGame()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE and not MainGame.TANK_P1:
                    self.createMyTank()
                if MainGame.TANK_P1 and MainGame.TANK_P1.live:
                    if event.key == pygame.K_LEFT:
                        print("The Tank move left")
                        MainGame.TANK_P1.direction = 'L'
                        MainGame.TANK_P1.stop = False
                    elif event.key == pygame.K_RIGHT:
                        print("The Tank move right")
                        MainGame.TANK_P1.direction = 'R'
                        MainGame.TANK_P1.stop = False
                    elif event.key == pygame.K_UP:
                        print("The Tank move up")
                        MainGame.TANK_P1.direction = 'U'
                        MainGame.TANK_P1.stop = False
                    elif event.key == pygame.K_DOWN:
                        print("The Tank move down")
                        MainGame.TANK_P1.direction = 'D'
                        MainGame.TANK_P1.stop = False
                    elif event.key == pygame.K_SPACE:
                        print("Fire bullets:%d" % len(MainGame.Bullet_list))
                        if len(MainGame.Bullet_list) < 3:
                            m = Bullet(MainGame.TANK_P1)
                            MainGame.Bullet_list.append(m)
                        else:
                            print("There is no bullet!")
            if event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT or event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                    if MainGame.TANK_P1 and MainGame.TANK_P1.live:
                        MainGame.TANK_P1.stop = True

    def getTextSurface(self, text):
        pygame.font.init()
        # check the system fonts
        # fontList = pygame.font.get_fonts()
        font = pygame.font.SysFont('cousine', 35)
        textSurface = font.render(text, True, color_textSurface)
        return textSurface

    def endGame(self):
        print("See you again!")
        exit()


class BaseItem(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)


class Tank(BaseItem):
    def __init__(self, left, top):
        self.images = {
            'U': pygame.image.load('images/Tank_UP.png'),
            'D': pygame.image.load('images/Tank_DOWN.png'),
            'L': pygame.image.load('images/Tank_LEFT.png'),
            'R': pygame.image.load('images/Tank_RIGHT.png')
        }
        self.direction = 'U'
        self.image = self.images[self.direction]
        self.image.set_colorkey(color_bg)
        self.image.convert_alpha()
        self.rect = self.image.get_rect()
        # the initial position
        self.rect.left = left
        self.rect.top = top
        self.speed = 10
        self.stop = True
        self.live = True
        self.oldLeft = self.rect.left
        self.oldTop = self.rect.top

    def move(self):
        self.oldLeft = self.rect.left
        self.oldTop = self.rect.top
        if self.direction == 'L':
            if self.rect.left > 0:
                self.rect.left -= self.speed
        elif self.direction == 'R':
            # the width and height is rect's virtual attributes
            if self.rect.left + self.rect.width < MainGame.screen_width:
                self.rect.left += self.speed
        elif self.direction == 'U':
            if self.rect.top > 0:
                self.rect.top -= self.speed
        elif self.direction == 'D':
            if self.rect.top + self.rect.height < MainGame.screen_height:
                self.rect.top += self.speed

    def stay(self):
        self.rect.left = self.oldLeft
        self.rect.top = self.oldTop

    def collisionWalls(self):
        for wall in MainGame.Wall_list:
            if pygame.sprite.collide_rect(wall, self):
                self.stay()

    def shot(self):
        return Bullet(self)

    def displayTank(self):
        self.image = self.images[self.direction]
        MainGame.window.blit(self.image, self.rect)


class MyTank(Tank):
    def __init__(self, left, top):
        super(MyTank, self).__init__(left, top)

    def hitEnemyTank(self):
        for eTank in MainGame.EnemyTank_list:
            if pygame.sprite.collide_rect(eTank, self):
                self.stay()


class EnemyTank(Tank):
    def __init__(self, left, top, speed):
        super(EnemyTank, self).__init__(left, top)
        self.images = {
            'U': pygame.image.load('images/Enemy_UP.png'),
            'D': pygame.image.load('images/Enemy_DOWN.png'),
            'L': pygame.image.load('images/Enemy_LEFT.png'),
            'R': pygame.image.load('images/Enemy_RIGHT.png')
        }
        self.direction = self.randDirection()
        self.image = self.images[self.direction]
        self.rect = self.image.get_rect()
        # the initial position
        self.rect.left = left
        self.rect.top = top
        self.speed = speed
        self.stop = True
        self.step = 100

    def randDirection(self):
        num = random.randint(1, 4)
        if num == 1:
            return 'U'
        elif num == 2:
            return 'D'
        elif num == 3:
            return 'L'
        elif num == 4:
            return 'R'

    def randMove(self):
        if self.step <= 0:
            self.direction = self.randDirection()
            self.step = 5
        else:
            self.move()
            self.step -= 1

    def shot(self):
        num = random.randint(1, 100)
        if num == 1:
            return Bullet(self)

    def hitMyTank(self):
        if pygame.sprite.collide_rect(self, MainGame.TANK_P1):
            self.stay()


class Bullet(BaseItem):
    def __init__(self, tank):
        self.image = pygame.image.load('images/Bullet.png')
        self.direction = tank.direction
        self.rect = self.image.get_rect()
        self.speed = tank.speed * 1.5
        self.live = True
        if self.direction == 'U':
            self.rect.left = tank.rect.left + tank.rect.width / 2 - self.rect.width / 2
            self.rect.top = tank.rect.top - self.rect.height
        elif self.direction == 'D':
            self.rect.left = tank.rect.left - self.rect.left - tank.rect.width
            self.rect.top = tank.rect.top - self.rect.top
        elif self.direction == 'L':
            self.rect.left = tank.rect.left - self.rect.width
            self.rect.top = tank.rect.top + tank.rect.width / 2 - self.rect.width / 2
        elif self.direction == 'R':
            self.rect.left = tank.rect.left + tank.rect.width
            self.rect.top = tank.rect.top + tank.rect.height / 2 - self.rect.width / 2

    def BulletMove(self):
        if self.direction == 'U':
            if self.rect.top > 0:
                self.rect.top -= self.speed
            else:
                self.live = False
        elif self.direction == 'D':
            if self.rect.top + self.rect.height < MainGame.screen_height:
                self.rect.top += self.speed
            else:
                self.live = False
        elif self.direction == 'L':
            if self.rect.left > 0:
                self.rect.left -= self.speed
            else:
                self.live = False
        elif self.direction == 'R':
            if self.rect.left + self.rect.width < MainGame.screen_width:
                self.rect.left += self.speed
            else:
                self.live = False

    def displatBullet(self):
        MainGame.window.blit(self.image, self.rect)

    def hitEnemyTank(self):
        for eTank in MainGame.EnemyTank_list:
            if pygame.sprite.collide_rect(eTank, self):
                self.live = False
                eTank.live = False

    def hitMyTank(self):
        if pygame.sprite.collide_rect(self, MainGame.TANK_P1):
            self.live = False
            MainGame.TANK_P1.live = False

    def hitWalls(self):
        for wall in MainGame.Wall_list:
            if pygame.sprite.collide_rect(wall, self):
                self.live = False
                wall.hp -= 1
                if wall.hp <= 0:
                    wall.live = False


class Wall():
    def __init__(self, left, top):
        self.image = pygame.image.load('images/Wall.webp')
        self.rect = self.image.get_rect()
        self.rect.left = left
        self.rect.top = top

        self.live = True
        self.hp = 3

    def displayWall(self):
        MainGame.window.blit(self.image, self.rect)


class Music():
    def __init__(self, fileName):
        self.fileName = fileName
        pygame.mixer.init()
        pygame.mixer.music.load(self.fileName)

    def play(self):
        pygame.mixer.music.play(loops=-1)


if __name__ == "__main__":
    MainGame().startGame()
