int   myprint(const   char*   format,...)                                                   //�������������...
{
	char   str[1024]={0};
	int   i=0;
					va_list   list;                                                                               //typedef   char*   va_list,һ��ָ���ַ����͵�ָ��
	va_start(list,format);                                               //��list����Ϊָ��ɱ�����ĵ�һ������
	while   (*format   !=   '\0 ')
	{
	if   (*format   ==   '% ')
	{
	switch   (*(++format))
	{
	case   'd ':
	itoa(va_arg(list,int),(str+i),10);                         //ԭ�ͣ�va_arg(va_list   list,type),����list������Ϊtype�ĵ�ǰ�Ĳ�����   ����listָ����һ����������ԭ����  
	i=strlen(str);                                                                                 //���ݵ�ǰָ��list��sizeof(type)���Ӷ�ʵ��ָ��ָ����һ������
	break;
	case   'c ':
	str[i++]=va_arg(list,char);                                   //va_arg���������һ��Ϊva_list���ͣ��ڶ���Ϊ��������������
	break;
	case   's ':
																	strcat(str,va_arg(list,char*));                             //����va_arg�꣬���ص�ǰ����������listָ����һ���ɱ����������У�
	break;
	}
	format++;
	continue;
	}
									str[i++]=*format;
	format++;
	}
	va_end(list);                                                         //��������list����ָ������ΪNULL
					puts(str);
					return   (int)strlen(str);
}