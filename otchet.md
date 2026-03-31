# Основная часть
1. Переходим в нашу папочку.
```sh
cd ~/${GITHUB_USERNAME}/workspace
```
2. Клонирование lab02 в lab03 и смена remote
```sh
git clone https://github.com/${GITHUB_USERNAME}/lab02.git projects/lab03
cd projects/lab03
git remote remove origin
git remote add origin https://github.com/${GITHUB_USERNAME}/lab03.git
```
3.  Cборка (g++)
```sh
# Компилируем print.cpp в объектный файл
g++ -std=c++11 -I./include -c sources/print.cpp
ls print.o
# Проверяем символы
nm print.o | grep print

# Создаём статическую библиотеку
ar rvs print.a print.o
file print.a

# Компилируем example1
g++ -std=c++11 -I./include -c examples/example1.cpp
ls example1.o

# Линкуем example1 с библиотекой
g++ example1.o print.a -o example1
./example1 && echo

# Компилируем example2
g++ -std=c++11 -I./include -c examples/example2.cpp
nm example2.o
g++ example2.o print.a -o example2
./example2
cat log.txt && echo
```
<details>
<summary>Проверяем символы</summary>
0000000000000000 T _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSo
0000000000000028 T _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSt14basic_ofstreamIcS2_E
</details>

<details>
<summary>Линкуем с библиотекой example</summary>
<pre>
./example1 && echo
hello
</pre>
</details>


<details>
<summary>Компиляция</summary>
  <pre>
nm example2.o
g++ example2.o print.a -o example2
./example2
cat log.txt && echo
0000000000000000 V DW.ref.__gxx_personality_v0
                 U __gxx_personality_v0
0000000000000000 T main
                 U memcpy
                 U __stack_chk_fail
                 U __stack_chk_guard
                 U strlen
                 U _Unwind_Resume
                 U _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSt14basic_ofstreamIcS2_E
                 U _ZdlPv
0000000000000000 W _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv
0000000000000000 W _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
0000000000000000 W _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
0000000000000000 W _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
0000000000000000 W _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv
0000000000000000 W _ZNSt11char_traitsIcE4copyEPcPKcm
0000000000000000 W _ZNSt11char_traitsIcE6assignERcRKc
0000000000000000 W _ZNSt11char_traitsIcE6lengthEPKc
                 U _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
                 U _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev
0000000000000000 W _ZNSt15__new_allocatorIcE10deallocateEPcm
0000000000000000 W _ZNSt15__new_allocatorIcE8allocateEmPKv
0000000000000000 W _ZNSt15__new_allocatorIcED1Ev
0000000000000000 W _ZNSt15__new_allocatorIcED2Ev
0000000000000000 n _ZNSt15__new_allocatorIcED5Ev
0000000000000000 W _ZNSt19__ptr_traits_ptr_toIPccLb0EE10pointer_toERc
0000000000000000 W _ZNSt19__ptr_traits_ptr_toIPKcS0_Lb0EE10pointer_toERS0_
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_S_allocateERS3_m
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_
0000000000000000 n _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC5EPcRKS3_
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
0000000000000000 n _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD5Ev
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm
00000000000add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF

cat >> CMakeLists.txt <<EOF

target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF

# Пересобираем всё
cmake --build _build

# Можно собирать отдельные цели
cmake --build _build --target print
cmake --build _build --target example1
cmake --build _build --target example2

# Проверяем
ls -la _build/libprint.a
_build/example1 && echo
_build/example2
cat log.txt && echo
rm -rf log.txt
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab03/_build
[ 33%] Built target print
[ 50%] Building CXX object CMakeFiles/example1.dir/examples/example1.cpp.o
[ 66%] Linking CXX executable example1
[ 66%] Built target example1
[ 83%] Building CXX object CMakeFiles/example2.dir/examples/example2.cpp.o
[100%] Linking CXX executable example2
[100%] Built target example2
[100%] Built target print
[ 50%] Built target print
[100%] Built target example1
[ 50%] Built target print
[100%] Built target example2
-rw-rw-r-- 1 vboxuser vboxuser 2382 Mar 31 20:19 _build/libprint.a
hello
hello
00000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEm
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_
0000000000000000 n _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5EPKcRKS3_
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
0000000000000000 W _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev
0000000000000000 n _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED5Ev
                 U _Znwm
                 U _ZSt17__throw_bad_allocv
                 U _ZSt19__throw_logic_errorPKc
                 U _ZSt20__throw_length_errorPKc
                 U _ZSt21ios_base_library_initv
0000000000000000 W _ZSt3minImERKT_S2_S2_
0000000000000008 r _ZStL19piecewise_construct
0000000000000000 r _ZStL6ignore
0000000000000000 W _ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardC1EPS4_
0000000000000000 W _ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardC2EPS4_
0000000000000000 n _ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardC5EPS4_
0000000000000000 W _ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD1Ev
0000000000000000 W _ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD2Ev
0000000000000000 n _ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD5Ev
hello
</pre>
</details>

4.Очистка
   ```sh
   rm -rf example1.o example2.o print.o print.a example1 example2 log.txt
   ```
5. Создание CMakeLists.txt поэтапнo

```sh
cat > CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.4)
project(print)
EOF

cat >> CMakeLists.txt <<EOF
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
EOF

cat >> CMakeLists.txt <<EOF
add_library(print STATIC \${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
EOF

cat >> CMakeLists.txt <<EOF
include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF

# Конфигурируем и собираем библиотеку
cmake -H. -B_build
cmake --build _build
```
# Установочка нужных паков!
```sh
sudo apt  install cmake  # version 3.31.6-2ubuntu6
sed -i 's/3.4/3.10/' CMakeLists.txt
cmake -H. -B_build
```

6. Добавление исполняемых файлов в CMakeLists.txt
```sh
cat >> CMakeLists.txt <<EOF

add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF

cat >> CMakeLists.txt <<EOF

target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF

# Пересобираем всё
cmake --build _build

# Можно собирать отдельные цели
cmake --build _build --target print
cmake --build _build --target example1
cmake --build _build --target example2

# Проверяем
ls -la _build/libprint.a
_build/example1 && echo
_build/example2
cat log.txt && echo
rm -rf log.txt
```
<details>
<summary>Компиляция</summary>
<pre>
add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF

cat >> CMakeLists.txt <<EOF

target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF

 Пересобираем всё
cmake --build _build

 Можно собирать отдельные цели
cmake --build _build --target print
cmake --build _build --target example1
cmake --build _build --target example2

 Проверяем
ls -la _build/libprint.a
_build/example1 && echo
_build/example2
cat log.txt && echo
rm -rf log.txt
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab03/_build
[ 33%] Built target print
[ 50%] Building CXX object CMakeFiles/example1.dir/examples/example1.cpp.o
[ 66%] Linking CXX executable example1
[ 66%] Built target example1
[ 83%] Building CXX object CMakeFiles/example2.dir/examples/example2.cpp.o
[100%] Linking CXX executable example2
[100%] Built target example2
[100%] Built target print
[ 50%] Built target print
[100%] Built target example1
[ 50%] Built target print
[100%] Built target example2
-rw-rw-r-- 1 vboxuser vboxuser 2382 Mar 31 20:19 _build/libprint.a
hello
hello
</pre>
</details>

```sh
$ git clone https://github.com/tp-labs/lab03 tmp
$ mv -f tmp/CMakeLists.txt .
$ rm -rf tmp

$ cat CMakeLists.txt
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
$ cmake --build _build --target install
$ tree _install

$ git add CMakeLists.txt
$ git commit -m"added CMakeLists.txt"
$ git push origin master
```



<details>
<summary>Итоги</summary>
<pre>
Username for 'https://github.com': Arkhamrus69
Password for 'https://Arkhamrus69@github.com': 
Перечисление объектов: 31, готово.
Подсчет объектов: 100% (31/31), готово.
При сжатии изменений используется до 4 потоков
Сжатие объектов: 100% (19/19), готово.
Запись объектов: 100% (31/31), 7.45 КиБ | 7.45 МиБ/с, готово.
Total 31 (delta 5), reused 27 (delta 4), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (5/5), done.
To https://github.com/Arkhamrus69/lab03.git
 + ea49ec8...c9eb71f main -> main (forced update)
</pre>
</details>

