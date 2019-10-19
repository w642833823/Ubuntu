#include <stdio.h>
#include <conio.h>
#include <unistd.h>


// 实现冒泡排序算法
// 给出要比较的数组，以及数组元素的个数
void BubbleSert(int a[], int n)
{
	int i, j, temp;
	// count1,2为总比较和交换次数，3,4为每一趟的次数
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	// 在算法中表示第某趟比较，也表示本次比较到第k个元素为止
	int k = 0;
	// 当为假时退出循环
	int flag = 1;

	for (i = k; i < n && flag; i++)
	{
		flag = 0;
		

		for (j = n - 1; j > i; j--)
		{
			count1++;
			count3++;
			// 实现交换
			if (a[j] < a[j - 1])
			{
				// 交换位置
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				count2++;
				count4++;
				// 位置有交换，所以flag为1
				flag = 1;
			}
				
		}
		k++;
		sleep(1);
		printf("\n------------------------------\n");
		printf("\033[1;35;33m\t第%d趟改进，共比较了%d次，进行了%d次交换\n\033[0m", k,
			   count3, count4);


		for (int z = 0; z < n; z++)
		{
			//输出排序详细过程
			printf("%d ", a[z]);
			

		}
		
		count3 = 0;
		count4 = 0;
		printf("\n------------------------------\n");

	}
	printf("\t总共比较了:%d次,进行了%d次交换", count1, count2);


}





int main()
{
	int n;
	printf("你准备写几个数，进行冒泡排序\n");
	scanf("%d", &n);
	int arr[n];
	printf("请输入%d个要排序的数\n\n", n);

	for (int i = 0; i <n; i++)
	{
		printf("请输入第%d个数\n",i);
		scanf("%d", &arr[i]);
	}

	printf("\t未排序前\n");
	for (int g = 0; g < n; g++)
	{

		printf("%d ", arr[g]);
	}
	printf("\n");
	// 开始冒泡排序

	BubbleSert(arr, n);
	printf("\n\n");
	printf("\t排序后:\n");

	for (int i = 0; i < n; i++)
	{

		printf("%d ", arr[i]);

	}
	printf("\n");
	

}