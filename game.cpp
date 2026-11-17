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

void visitShelter() {
    if (resources < kCampCost) {
        std::cout << "\nНе хватает крышек на аптечку. Нужно "
                  << kCampCost << ", у вас " << resources << ".\n";
        return;
    }

    resources -= kCampCost;
    const int requestedHeal = 25 + std::rand() % 21;
    const int oldHp = hp;
    hp = std::min(kMaxHp, hp + requestedHeal);
    std::cout << "\nВы использовали аптечку за " << kCampCost
              << " крышек и восстановили " << (hp - oldHp) << " HP.\n";
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
                visitShelter();
                break;
            case 3:
                std::cout << "\nМодуль случайных событий в разработке (Issue #3).\n";
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
