int *find_pivot(int *low, int *high);
int *adjust(int *low, int *high);
void quick_sort(int *low, int *high);

int *find_pivot(int *low, int *high)
{
	int *mid = low + (high - low) / 2;
	int *smaller, *bigger;
	if (*low < *mid)
	{
		smaller = low;
		bigger = mid;
	}
	else
	{
		smaller = mid;
		bigger = low;
	}
	if (*high <= *smaller)
	{
		return smaller;
	}
	else
	{
		return (*bigger <= *high) ? bigger : high;
	}
}

//int *find_pivot(int *low, int *high)
//{
//	return low + (high - low) / 2;
//}

void quick_sort(int *low, int *high)
{
	if (low >= high) return;
	else
	{
		int *pivot = adjust(low, high);
		quick_sort(low, pivot);
		quick_sort(pivot+1, high);
	}
}

int *adjust(int *low, int *high)
{
	int *pivot = find_pivot(low, high);
	//phase_1
	while (low < pivot)
	{
		if (*low <= *pivot)
		{
			low++;	//do nothing
		}
		else	//there is an element on the left larger then the pivot, find a smaller element on the right to swap
		{
			while (*high > *pivot && high > pivot)	//search for the first element on the right smaller than the pivot
			{
				high--;
			}
			if (high == pivot)
			{
				break;	//search failed, continue to phase_2
			}
			else	//found an element, swap the values
			{
				int tmp;
				tmp = *low;
				*low = *high;
				*high = tmp;
				low++;
			}
		}
	}

	while (low < high)
	{
		//phase_2
		if (low == pivot)	//case 1, direction = right->left
		{
			if (*high >= *pivot)
			{
				high--;	//do nothing
			}
			else
			{
				int tmp;
				//swap the values
				tmp = *pivot;
				*pivot = *high;
				*high = tmp;
				//adjust the pointers
				pivot = high;
			}
		}
		else	//case 2, direction = left->right
		{
			if (*low <= *pivot)
			{
				low++;	//do nothing
			}
			else
			{
				int tmp;
				//swap the values
				tmp = *pivot;
				*pivot = *low;
				*low = tmp;
				//adjust the pointers
				pivot = low;
			}
		}
	}
	return pivot;
}
