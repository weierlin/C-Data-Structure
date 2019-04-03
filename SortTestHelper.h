//
// Created by weierLin on 7/12/16.
//
#include <iostream>
#include <ctime>
#include <cassert>
#include <stdlib.h>
#include <string>

namespace SortTestHelper {

    // ������n��Ԫ�ص��������,ÿ��Ԫ�ص������ΧΪ[rangeL, rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);

        int *arr = new int[n];

        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    // ��ӡarr�������������
    template<typename T>
    void printArray(T arr[], int n) {

        for (int i = 0; i < n; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
        return;
    }

    //��Ϊ����Ҫ�������ݺܴ��ܲ��ܽ��д�ӡ��
    template <typename T>
    bool isSorted(T arr[], int n){
        for(int i = 0; i < n; i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }

    template <typename T>
    void testSort(std::string sortName, void(*sort)(T[], int n), T arr[], int n){

        clock_t beginTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert( isSorted(arr, n));
        std::cout << sortName << " : " << double(endTime-beginTime)/CLOCKS_PER_SEC << "s" << std::endl;
    }

};
