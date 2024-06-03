// pointers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sum(int a)
{
    a = a + 2;
}
void sum_ptr(int *a)
{
    *a = *a + 2;
}
void* append(short* arr, size_t* length, size_t* capacity, short value);

 typedef struct tag_point {
    int x;
    int y;
    int z;
} point;

 typedef struct tag_object {
     int data;
     struct tag_object* next;
 } OBJ;

 OBJ* push(OBJ* top, int value)
 {
     OBJ* new_obj = (OBJ*)malloc(sizeof(OBJ));
     new_obj->data = value;
     new_obj->next = top;
     return new_obj;
 }
 OBJ* pop(OBJ* top)
 {
     if (top == NULL)
         return top;
     OBJ* ptr_next = top->next;
     free(top);
     return ptr_next;
 }
 void show(const OBJ* top)
 {
     const OBJ* current = top;
     while (current != NULL)
     {
         printf("%d ", current->data);
         current = current->next;
     }
 }

int main()
{
    srand(time(NULL));
    char d = 10;
    char* ptr = &d;
    printf("Value: %d Address: %p\n", *ptr, ptr);
    char* ptr2 = ptr + 1;
    printf("Value: %d Address: %p\n", *ptr2, ptr2);
    *ptr = *ptr + 1;
    printf("Value: %d Address: %p\n", *ptr, ptr);
    // Sum function
    int a = 3;
    sum(a);
    printf("Func without pointers: %d\n", a);
    sum_ptr(&a);
    printf("Func with pointers: %d\n", a);
    // Адресная арифметика
    int g = 11;
    int* pt = &g;
    printf("pt = %d", pt);
    pt++;
    printf(" pt++ = %d\n\n", pt);
    // Массивы
    int arr[] = { 1,2,3,4,5 };
    int arr_size = sizeof(arr) / sizeof(int);
    int* ptr_arr = arr;
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", *ptr_arr++);
    }
    // Операции с массивами
    float func_1[100] = { 2.4, -3.8, 0, 10.2, 11.78, -5.43 };
    float func_2[50];
    for (int i = 0; i < 50; i++)
    {
        func_2[i] = func_1[i];
        printf("%d ", func_2[i]);
    }
    printf("\n\n");
    // Выделение памяти
    int* ptr_ar = (int*)malloc(sizeof(int) * 10);
    printf("%p\n", ptr_ar);
    free(ptr_ar);

    // Динамический массив
    size_t length = 0;
    size_t capacity = 10;
    short* data = (short*)malloc(capacity * sizeof(short));
    for (int i = 0; i < 20; i++)
    {
        data = (short*)append(data, &length, &capacity, rand() % 100);
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    
    printf("\n");

    // Структуры
    point s_point;
    s_point.x = 20;
    s_point.y = 10;
    s_point.z = 5;
    printf("%zd\n", sizeof(point));
    point d_point = { 10,20,30 };
    // Массив структур
    point figure[10]; // фигура, состоящая из 10 точек
    figure[0] = point{ 10,20,30 };
    figure[1] = point{ 7, 5, 2 };
    
    // Указатель на структуру
    point p_point;
    point* ptr_point = &p_point;
    ptr_point->x = 20;
    ptr_point->y = 10;
    ptr_point->z = 30;
    point* arr_point = (point*)malloc(sizeof(point) * 10);
    arr_point[0] = { 10,5,10 };
    arr_point[1] = { 7, 2, 3 };
    arr_point[2] = { 3,1,4 };
    for (int i = 0; i < 3; i++)
    {
        printf("x: %d y: %d z: %d \n", arr_point[i].x, arr_point[i].y, arr_point[i].z);
    }
    free(arr_point);

    // Реализация стека
    OBJ* top = NULL;
    top = push(top, 20);
    top = push(top, 40);
    top = push(top, 50);
    show(top);

}
void* append(short* arr, size_t* length, size_t* capacity, short value)
{
    // Массив переполнен, нужно выделить новую память
    (*capacity) *= 2;
    if (*length >= *capacity)
    {
        short* new_arr = (short*)realloc(arr, sizeof(short*) * *capacity);
        if (new_arr == NULL) return arr;
        arr = new_arr;
    }
    arr[*length] = value;
    (*length)++;
    return arr; // вернули адрес, т.к. он может поменяться в функции
}

