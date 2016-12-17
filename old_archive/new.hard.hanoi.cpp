#include <iostream>

using namespace std;

// Сложение по модулю 3
// Используется для cмещения как с шагом = +1: AddMod3(op1, 1)
// так и с шагом = -1:   AddMod3(op1, 2)
inline unsigned AddMod3(unsigned op1, unsigned op2)
{
    return  ((op1 + op2) % 3);
}

// Описание одного стержня
struct Pivot {
    unsigned disk_number; // Текущее количество дисков на стержне
    unsigned *disk_list;  // Список дисков, размещенных на стержне
};

// Набор из трех стержней
struct Pivots {
    Pivot pivot[3];
    Pivots(unsigned disks); // Начальная конфигурация стержней
    ~Pivots(); // "Разрушение" стержней по завершению вычислений
};

// Начальная конфигурация стержней
Pivots::Pivots(unsigned disks)
{
    // Создается муляж для хранения дисков
    for(int i = 0; i < 3; i++) {
        pivot[i].disk_list = new unsigned[disks+1];
        pivot[i].disk_number = 0;
        // Заглушка, срабатывающая при нулевом числе дисков
        pivot[i].disk_list[0] = disks + 1;
    }

    // Нулевой стержень заполняется дисками таким образом,
    // чтобы номер диска совпадал с индексом
    for(int i = 1; i <= disks; i++) {
        pivot[0].disk_list[i] = disks - i + 1;
    }
    pivot[0].disk_number = disks;
}

// "Разрушение" стержней по завершению вычислений
Pivots::~Pivots()
{
    for(int i = 0; i < 3; i++)
        delete[] pivot[i].disk_list;
}

// Печать результатов по проделанному шагу
inline void out(unsigned count, unsigned src, unsigned rec, Pivots &p)
{
    cout << count << ":\t " << src << " -> " << rec
         << "\t\t pivots: "
         << p.pivot[0].disk_number << "\t"
         << p.pivot[1].disk_number << "\t"
         << p.pivot[2].disk_number << "\t"
         << " Disk = "
         << p.pivot[rec].disk_list[p.pivot[rec].disk_number]
         << endl;
}

inline void move(unsigned src, unsigned rec,
Pivots &p, unsigned &count)
{
    p.pivot[rec].disk_list[++p.pivot[rec].disk_number] =
        p.pivot[src].disk_list[p.pivot[src].disk_number--];
    out(++count, src, rec, p);
}

// Алгоритм, обеспечивающий моделирование ханойской башни
void hanoy(unsigned disks)
{
    unsigned count = 0; // счетчик перекладывания дисков
    // Шаг, определяющий перемещение верхнего диска (1 или 2)
    // для проверки на четность используется маскирование
    unsigned step = 1 + (disks & 1);
    // Шаг перемещения альтернативного стержня, на который,
    // или с которого (новый фундамент) перемещается следующий диск
    // Для определения этого шага достаточно вычесть основной шаг из 3
    unsigned alt_step = 3 - step;
    // Стержни с дисками
    Pivots p(disks);

    // Проверка наличия дисков
    if(disks < 1)
    {
        cout << "Disks are absent!" << endl;
        return;
    }

    // Начата разборка первой двухэтажной башни
    unsigned src = 0;
    unsigned rec = step;
    move(src, rec, p, count);

    if(disks < 2) return; // Конец строительства башни из 1-го диска

    // Перенос второго блока в основание двухэтажной башни
    unsigned alt = AddMod3(src, alt_step);
    move(src, alt, p, count);

    // Завершение строительства двухэтажной башни
    src = rec;
    rec = AddMod3(src, step);
    move(src, rec, p, count);

    if(disks < 3) return; // Конец строительства башни из 2-х дисков

    // Далее следуют итерации, содержащие по 4 типовых шага.
    // Выполнятся хотя бы раз при числе дисков больше двух.

    // Старая версия цикла
    //unsigned iterations = (1 << (disks - 2)) - 1; // Число итераций
    //for(unsigned i = 0; i < iterations; ++i)
    // Новая проверка на окончание вычислений,
    // доводящая количество дисков до абсурда.
    while(p.pivot[2].disk_number < disks)
    {
        // Формирование нового фундамента
        // Меньший диск перекладывается на больший
        // Участвуют исходный и альтернативный стержни
        // Новый альтернативный стержень не должен быть
        // предыдущим приемником
        alt = AddMod3(src, alt_step);
        if(    p.pivot[src].disk_list[p.pivot[src].disk_number] >
            p.pivot[alt].disk_list[p.pivot[alt].disk_number]
          )
        {
            // С альтернативного на исходный
            move(alt, src, p, count);
            //p.pivot[src].disk_list[++p.pivot[src].disk_number] =
            //    p.pivot[alt].disk_list[p.pivot[alt].disk_number--];
            //out(++count, alt, src, p);
        }
        else
        {
            // С исходного на альтернативный
            move(src, alt, p, count);
        }
        // Начата разборка двухэтажной башни
        src = rec;    // Прежний приемник становится источником
        rec = AddMod3(src, step); // Новый приемник
        move(src, rec, p, count);

        // Перенос второго блока в основание двухэтажной башни
        alt = AddMod3(src, alt_step); // Новый альтернативный стержень
        move(src, alt, p, count);

        // Завершение строительства двухэтажной башни
        src = rec;    // Прежний приемник становится источником
        rec = AddMod3(src, step); // Новый приемник
        move(src, rec, p, count);
    }

    cout << endl
         << "Used "
         << disks      << " disks. "
         << endl
         << "Make "
         << count << " steps."
         << endl;
}

main()
{
    unsigned disks;
    cout << "Input disk\'s number: ";
    cin >> disks;
    cout << "Hanoy with " << disks <<" disks:" << endl;
    hanoy(disks);
}
