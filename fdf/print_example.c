
printf("digits : %d, %d, %d, %d\n", data->x, data->y, data->max_x, data->max_y);
	int idx = 0;
	int row = 0;
	int col = 0;
	while (idx < 2)
	{
		col = 0;
		while (col < data->max_y)
		{
			row = 0;
			while (row < data->max_x)
			{
				printf("array data->data[%d][%d][%d] : %d\n" ,idx, col, row, data->data[idx][col][row]);
				row++;
			}
			col++;
		}
		idx++;
	}
