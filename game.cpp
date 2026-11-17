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

void riskyRaid() {
    std::cout << "\nВы отправились в логово мутантов...\n";
    const int roll = std::rand() % 100;

    if (roll < 50) {
        const int reward = 200 + std::rand() % 301;
        const int loot = 20 + std::rand() % 31;
        score += reward;
        resources += loot;
        std::cout << "Удачный рейд! +" << reward << " очков и +" << loot
                  << " крышек.\n";
    } else {
        const int damage = 30 + std::rand() % 21;
        hp = std::max(0, hp - damage);
        std::cout << "Мутанты ранили вас. -" << damage << " HP.\n";
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
                riskyRaid();
                break;
            case 2:
                std::cout << "\nМодуль убежища в разработке (Issue #2).\n";
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
