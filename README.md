# Laboratory Work II

## Version Control Systems (Git)

### Цель работы

Изучение систем контроля версий Git и освоение базовых операций работы с удалённым репозиторием на GitHub.

---

## Выполненные задания

### 1. Создание публичного репозитория

Был создан публичный репозиторий **lab02** на GitHub с лицензией MIT.

---

### 2. Генерация токена доступа

Сгенерирован персональный токен доступа (Personal Access Token) с правами `repo` для работы с GitHub через командную строку.

---

### 3. Выполнение инструкции

#### Настройка окружения

```bash
export GITHUB_USERNAME=<username>
export GITHUB_EMAIL=<email>
export GITHUB_TOKEN=<token>
alias edit=nano

cd ${GITHUB_USERNAME}/workspace
source scripts/activate
```

#### Настройка доступа к GitHub

```bash
mkdir ~/.config
cat > ~/.config/hub <<EOF
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF

git config --global hub.protocol https
```

---

#### Создание проекта

```bash
mkdir -p projects/lab02
cd projects/lab02
git init
```

#### Настройка Git

```bash
git config --global user.name ${GITHUB_USERNAME}
git config --global user.email ${GITHUB_EMAIL}
git config -e --global
```

---

#### Подключение удалённого репозитория

```bash
git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git
git pull origin master
```

---

#### Добавление README

```bash
touch README.md
git add README.md
git commit -m "added README.md"
git push origin master
```

---

#### Добавление `.gitignore`

Содержимое файла:

```
*build*/
*install*/
*.swp
.idea/
```

```bash
git pull origin master
git log
```

---

#### Создание структуры проекта

```bash
mkdir sources include examples
```

---

#### Исходные файлы

**sources/print.cpp**

```cpp
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
```

**include/print.hpp**

```cpp
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
```

**examples/example1.cpp**

```cpp
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
```

**examples/example2.cpp**

```cpp
#include <print.hpp>
#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
```

---

#### Финальный коммит

```bash
git add .
git commit -m "added sources"
git push origin master
```

---
git init - с помощью этой команды я создаю новый локальный репозиторий в папке проекта, после этого Git начинает отслеживать изменения файлов

git config --global user.name - здесь я указываю своё имя, которое будет записываться в каждый коммит

git config --global user.email - указываю свою почту, она тоже привязывается к коммитам

git remote add origin <url> - этой командой я подключаю удалённый репозиторий на GitHub к своему проекту

git pull origin master - скачиваю изменения из удалённого репозитория, чтобы синхронизироваться перед началом работы

git status - проверяю текущее состояние проекта: какие файлы изменены, какие добавлены, а какие ещё не отслеживаются

git add <file/dir> -  говорю Git, какие именно изменения нужно включить в следующий коммит

git commit -m "message" - сохраняю изменения в истории проекта с комментарием, чтобы было понятно, что именно я сделал

git push origin master - отправляю все свои коммиты в удалённый репозиторий на GitHub

git log - смотрю историю всех коммитов, чтобы отследить изменения и при необходимости вернуться к предыдущим версиям




# Homework

Задание 1
Вам поручили перейти на систему автоматизированной сборки CMake. Исходные файлы находятся в директории formatter_lib. В этой директории находятся файлы для статической библиотеки formatter. Создайте CMakeList.txt в директории formatter_lib, с помощью которого можно будет собирать статическую библиотеку formatter.

Задание 2
У компании "Formatter Inc." есть перспективная библиотека, которая является расширением предыдущей библиотеки. Т.к. вы уже овладели навыком созданием CMakeList.txt для статической библиотеки formatter, ваш руководитель поручает заняться созданием CMakeList.txt для библиотеки formatter_ex, которая в свою очередь использует библиотеку formatter.

Задание 3
Конечно же ваша компания предоставляет примеры использования своих библиотек. Чтобы продемонстрировать как работать с библиотекой formatter_ex, вам необходимо создать два CMakeList.txt для двух простых приложений:

hello_world, которое использует библиотеку formatter_ex;
solver, приложение которое испольует статические библиотеки formatter_ex и solver_lib.

```sh
./build/hello_world/hello_world
./build/solver/solver
```
Итог:
-------------------------
hello, world!
-------------------------
-------------------------
Root: 2.000000
-------------------------



# Сборочка
<pre>
vboxuser@Ubunta:~/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab03$ cmake --build build
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab03/build
[ 10%] Building CXX object formatter_lib/CMakeFiles/formatter.dir/formatter.cpp.o
[ 20%] Linking CXX static library libformatter.a
[ 20%] Built target formatter
[ 30%] Building CXX object formatter_ex_lib/CMakeFiles/formatter_ex.dir/formatter_ex.cpp.o
[ 40%] Linking CXX static library libformatter_ex.a
[ 40%] Built target formatter_ex
[ 50%] Building CXX object solver_lib/CMakeFiles/solver_lib.dir/solver.cpp.o
[ 60%] Linking CXX static library libsolver_lib.a
[ 60%] Built target solver_lib
[ 70%] Building CXX object hello_world/CMakeFiles/hello_world.dir/main.cpp.o
[ 80%] Linking CXX executable hello_world
[ 80%] Built target hello_world
[ 90%] Building CXX object solver/CMakeFiles/solver.dir/main.cpp.o
[100%] Linking CXX executable solver
[100%] Built target solver
</pre>
