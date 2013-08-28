int   myprint(const   char*   format,...)                                                   //必须是三个点号...
{
	char   str[1024]={0};
	int   i=0;
					va_list   list;                                                                               //typedef   char*   va_list,一个指向字符类型的指针
	va_start(list,format);                                               //把list设置为指向可变参数的第一个参数
	while   (*format   !=   '\0 ')
	{
	if   (*format   ==   '% ')
	{
	switch   (*(++format))
	{
	case   'd ':
	itoa(va_arg(list,int),(str+i),10);                         //原型：va_arg(va_list   list,type),返回list中类型为type的当前的参数，   并将list指向下一个参数（其原理是  
	i=strlen(str);                                                                                 //根据当前指针list＋sizeof(type)，从而实现指针指向下一个参数
	break;
	case   'c ':
	str[i++]=va_arg(list,char);                                   //va_arg宏参数：第一个为va_list类型，第二个为参数的数据类型
	break;
	case   's ':
																	strcat(str,va_arg(list,char*));                             //调用va_arg宏，返回当前参数，并且list指向下一个可变参数（如果有）
	break;
	}
	format++;
	continue;
	}
									str[i++]=*format;
	format++;
	}
	va_end(list);                                                         //重新设置list，把指针设置为NULL
					puts(str);
					return   (int)strlen(str);
}