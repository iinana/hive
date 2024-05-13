#include "main.h"

void	set_chars(t_info *info, char e, char o, char f)
{
	info->empt = e;
	info->obst = o;
	info->full = f;
}

// infile에 있는 map 중 x번째 row를 하나의 문자열로 만들어 리턴
// std일 때는 infile을 0으로, file일 때는 해당 파일 정보를 넣어서 실행
char	*map_array(int infile, unsigned int x, t_info *info)
{
	char			*array;
	char			c;
	unsigned int	y;

	// column만큼 메모리 할당
	array = (char *)malloc(sizeof(char) * (info->y));
	if (array == NULL)
		return (NULL);

	// column만큼 반복하며 한글자씩 채우기
	y = 0;
	while (y < info->y)
	{
		if (read(infile, &c, 1) < 0 || !is_allowed(c, info))
			return (NULL);
		array[y++] = c;
	}
	if (x != (info->x - 1) && (read(infile, &c, 1) < 0 || c != '\n'))
		return (NULL);
	return (array);
}

int	is_allowed(char c, t_info *info)
{
	if (c != info->empt && c != info->obst && c != info->full)
		return (0);
	if (c < 32 || c > 126)
		return (0);
	return (1);
}