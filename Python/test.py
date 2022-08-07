from manim import *

class pointMovingOnShapes(Scene):
    def construct(self):
        square = Square(color = BLUE)
        square.flip(RIGHT)
        square.rotate(-3 * TAU / 8)
        
        self.play(GrowFromCenter(square))