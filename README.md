# Fallout: Battle for the High Score

Учебный проект для лабораторной №6 по GitHub Flow, Issues и Code Review.
Ветка main содержит стартовый шаблон; три игровых механики добавляются отдельными PR к Issues #1–#3.
Полная версия игры подготовлена отдельно как ветка release/demo-game.

## Сборка

~~~sh
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror game.cpp -o game
./game
~~~

## Задачи

- Рейд с высоким риском и наградой — Issue #1.
- Убежище, аптечка и крышки — Issue #2.
- Случайная встреча D20 — Issue #3.
