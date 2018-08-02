unsigned int LISS(const int array[], size_t length, int result[])
{
	unsigned int i, j, k, max;

	//变长数组参数，C99新特性，用于记录当前各元素作为最大元素的最长递增序列长度
	unsigned int liss[length];

	//前驱元素数组，记录当前以该元素作为最大元素的递增序列中该元素的前驱节点，用于打印序列用
	unsigned int pre[length];

	for (i = 0; i < length; ++i)
	{
		liss[i] = 1;
		pre[i] = i;
	}

	for (i = 1, max = 1, k = 0; i < length; ++i)
	{
		//找到以array[i]为最末元素的最长递增子序列
		for (j = 0; j < i; ++j)
		{
			//如果要求非递减子序列只需将array[j] < array[i]改成<=，
			//如果要求递减子序列只需改为>
			if (array[j] < array[i] && liss[j] + 1> liss[i])
			{
				liss[i] = liss[j] + 1;
				pre[i] = j;

				//得到当前最长递增子序列的长度，以及该子序列的最末元素的位置
				if (max < liss[i])
				{
					max = liss[i];
					k = i;
				}
			}
		}
	}

	//输出序列
	i = max - 1;

	while (pre[k] != k)
	{
		result[i--] = array[k];
		k = pre[k];
	}

	result[i] = array[k];

	return max;
}