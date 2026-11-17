#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

constexpr int kMaxHp = 100;
int hp = kMaxHp;
int resources = 50;
long long score = 0;
int turn = 1;

void printHUD() {
    std::cout << "\n========== ХОД " << turn << " | СЧЁТ " << score << " ==========\n";
    std::cout << "Здоровье: " << hp << "/" << kMaxHp
              << " | Крышки: " << resources << "\n";
    std::cout << "----------------------------------------------\n";
}

void randomEncounter() {
    const int roll = 1 + std::rand() % 20;
    std::cout << "\nБросок D20: " << roll << ". ";

    if (roll == 1) {
        const int damage = 30;
        hp = std::max(0, hp - damage);
        score = std::max(0LL, score - 100);
        std::cout << "Критическое проклятие! -" << damage
                  << " HP и -100 очков.\n";
    } else if (roll == 20) {
        score += 500;
        resources += 30;
        std::cout << "ДЖЕКПОТ! +500 очков и +30 крышек.\n";
    } else {
        int bonus = roll * 10;
        if (roll >= 18) {
            bonus *= 3;
            std::cout << "Критический множитель x3! ";
        }
        score += bonus;
        std::cout << "+" << bonus << " очков.\n";
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int choice = 0;
    std::cout << ">>> FALLOUT: БИТВА ЗА РЕКОРД <<<\n";

    while (hp > 0) {
        printHUD();
        std::cout << "1. Рейд в логово мутантов (риск / награда)\n";
        std::cout << "2. Убежище (аптечка за крышки)\n";
        std::cout << "3. Случайная встреча (D20)\n";
        std::cout << "0. Завершить игру\n";
        std::cout << "Ваш выбор > ";

        if (!(std::cin >> choice)) {
            std::cout << "\nВвод завершён или команда некорректна.\n";
            break;
        }

        switch (choice) {
            case 1:
                std::cout << "\nМодуль рейда в разработке (Issue #1).\n";
                break;
            case 2:
                std::cout << "\nМодуль убежища в разработке (Issue #2).\n";
                break;
            case 3:
                randomEncounter();
                break;
            case 0:
                hp = 0;
                break;
            default:
                std::cout << "\nТакого действия нет. Выберите 0, 1, 2 или 3.\n";
                break;
        }

        if (hp > 0 && choice != 0) {
            ++turn;
            score += 10;
        }
    }

    std::cout << "\nИГРА ОКОНЧЕНА. Итоговый рекорд: "
              << score << " очков.\n";
    return 0;
}
