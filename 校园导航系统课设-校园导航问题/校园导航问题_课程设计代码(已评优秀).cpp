#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define JD 50
#define INF 999999
typedef struct {
	char name[JD];/*����ص�����*/ 
	char xinxi[1000];/*����ص���Ϣ*/ 
} VertexType;/*��ͼ��Ϣ�Ķ���*/ 
typedef struct {
	VertexType vexs[JD];
	int edges[JD][JD];
	int v,e;
}MGraph;/*��ͼ������ͼ���ıߺͽڵ�Ķ���*/ 
static MGraph M;
void setColor();
void create();
void showjd();
void Showlj();
void jiemian();
void Introduce();
void Changejd();
void Increasejd();
void Deletejd();
void Increaselj();
void Deletelj();
void Zdlj();
void Zdlj_2();
int main(){
	create();
	while(1){
		system("cls");
		jiemian();
	}
	return 0;
}
void setColor(unsigned short ForeColor,unsigned short BackGroundColor){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);
}/*��������������ɫ�ĺ���*/ 
void jiemian(){
	setColor(9, 15);
	system("cls");
	int n=0;
	printf("\n\n		     ��ӭ�����б���ѧ��У��У԰�������ģ�    \n\n");
	printf("\n		            ��ѡ����Ҫ���еĲ�����           \n");
	printf("\n		        1.�鿴���еص�                       \n");
	printf("		        2.�鿴���е�·                       \n");
	printf("		        3.�޸����еص�                       \n");
	printf("		        4.�����µĵص�                       \n");
	printf("		        5.ɾ�����еص�                       \n");
	printf("		        6.�����µĵ�·                       \n");
	printf("		        7.ɾ�����е�·                       \n");
	printf("		        8.���ҵ�ǰ�ص㵽�����ص�����·��   \n");
	printf("		        9.������һ�������ص�֮������·��   \n");
	printf("		        10.�˳�ϵͳ��                        \n");
	printf("\n		            ע��:����������������֣�            \n\n");
	scanf("%d",&n);
	getchar();
	switch(n){
		case 1: Introduce(); break;
		case 2: Showlj(); break;
		case 3: Changejd(); break;
		case 4: Increasejd(); break;
		case 5: Deletejd(); break;
		case 6: Increaselj(); break;
		case 7: Deletelj(); break;
		case 8: Zdlj(); break;
		case 9: Zdlj_2(); break;
		case 10: system("cls"); printf("�˳��ɹ���\n"); exit(0);
		default: printf("���������������������룡\n"); system("pause"); break;
	}
}
void create() {
	M.v=15;//��¼��ĵص�����
	M.e=23;//��¼��ص�ĵ�·������
	int i,j,k;
	for(i=0; i<JD; i++){
		for(j=0; j<JD; j++){
			M.edges[i][j]=INF;
		}
	}
	strcpy(M.vexs[0].name,"У����");
	strcpy(M.vexs[0].xinxi,"�����б���ѧ������һ���ţ�����������ֻ�г���������;���е»�¥���»��㳡��������Ҳ�������");
	strcpy(M.vexs[1].name,"���������");
	strcpy(M.vexs[1].xinxi,"����һ����ı�׼���򳡺�ƹ����ݣ�ƹ������ڴ˴��Ͽ�");
	strcpy(M.vexs[2].name,"УҽԺ");
	strcpy(M.vexs[2].xinxi,"�����硢����Լ�����ʱ�����");
	strcpy(M.vexs[3].name,"����Է");
	strcpy(M.vexs[3].xinxi,"���ձ��ݵĵط�");
	strcpy(M.vexs[4].name,"����һ");
	strcpy(M.vexs[4].xinxi,"��Ʒ�ֶ࣬���۸�Ҳ��֮���ǣ��г��С�ҩ�ꡢΨһһ�����С��ӻ���");
	strcpy(M.vexs[5].name,"���ٳ�");
	strcpy(M.vexs[5].xinxi,"����һ����׼���ٳ��������ƺ�����򳡣��ʺ϶�������");
	strcpy(M.vexs[6].name,"ͼ���");
	strcpy(M.vexs[6].xinxi,"��ǳ��࣬��רҵ��ţ��ܺõ���ϰ����");
	strcpy(M.vexs[7].name,"����ѧ¥��");
	strcpy(M.vexs[7].xinxi,"¥�����б���ѧ�ĸ����ֵ�¥��Ҳ����11�Ž�ѧ¥���ܶ��������ϣ��ս���Ҳ�ܶ࣬¥ǰ��һ����㳡����֪�㳡�����ܶ����������");
	strcpy(M.vexs[8].name,"��Ժ¥");
	strcpy(M.vexs[8].xinxi,"�������е����ѧԺ���ӣ�¥���󣬵������˲Ų���Ŷ");
	strcpy(M.vexs[9].name,"9��¥");
	strcpy(M.vexs[9].xinxi,"�ܶ��Ҳ������ϣ����ҽ϶࣬��ѧԺ��Ҫ�����");
	strcpy(M.vexs[10].name,"14��¥");
	strcpy(M.vexs[10].xinxi,"�Ĳ�¥����ң�������Ŀ���");
	strcpy(M.vexs[11].name,"10��¥");
	strcpy(M.vexs[11].xinxi,"��ʱû������Ϲ��Σ�ֻ����������ԣ�����������Ľ�ѧ¥��");
	strcpy(M.vexs[12].name,"��԰��");
	strcpy(M.vexs[12].xinxi,"�������������Լ���԰ʳ�ã���԰ʵ���ң�ʳ�óԵĲ������ٱ��ˣ�ʳ������ʵ���ң�������߳�һ����һ��������˲š�");
	strcpy(M.vexs[13].name,"��ѧ¥��");
	strcpy(M.vexs[13].xinxi,"������ѧ�㳡����ѧ¥����������Ʒ�ĵط������и�Сʳ��");
	strcpy(M.vexs[14].name,"����");
	strcpy(M.vexs[14].xinxi,"������ĵط�");
	M.edges[0][1]=M.edges[1][0]=230;
	M.edges[0][3]=M.edges[3][0]=470;
	M.edges[1][7]=M.edges[7][1]=540;
	M.edges[2][3]=M.edges[3][2]=300;
	M.edges[2][7]=M.edges[7][2]=440;
	M.edges[3][4]=M.edges[4][3]=100;
	M.edges[3][6]=M.edges[6][3]=400;
	M.edges[4][5]=M.edges[5][4]=180;
	M.edges[5][6]=M.edges[6][5]=150;
	M.edges[5][7]=M.edges[7][5]=200;
	M.edges[6][7]=M.edges[7][6]=140;
	M.edges[7][8]=M.edges[8][7]=80;
	M.edges[7][9]=M.edges[9][7]=190;
	M.edges[8][10]=M.edges[10][8]=200;
	M.edges[8][13]=M.edges[13][8]=310;
	M.edges[9][10]=M.edges[10][9]=230;
	M.edges[10][11]=M.edges[11][10]=250;
	M.edges[10][13]=M.edges[13][10]=140;
	M.edges[10][14]=M.edges[14][10]=200;
	M.edges[11][12]=M.edges[12][11]=320;
	M.edges[11][13]=M.edges[13][11]=210;
	M.edges[11][14]=M.edges[14][11]=240;
	M.edges[12][13]=M.edges[13][12]=350;
}
void showjd(){
	if(M.v==0){
		printf("		��ǰ����ͼ��û�еص㣡\n\n");
		system("pause");
		return ;
	}
	if(M.v>0){
		printf("			�б���ѧ����ͼ��ǰ�����µص㣺  \n\n");
		for(int i=0; i<M.v; i++){
			printf("\t\t		<%d>%s		\n",i+1,M.vexs[i].name);
		}
	}
}/*չʾͼ�����нڵ�*/ 
void Showlj(){
	system("cls");
	if(M.e<=0){
		printf("		��ǰ����ͼ��û�е�·��\n\n");
		system("pause");
		return ;
	}
	if(M.e>0){
		printf("			�б���ѧ����ͼ��ǰ������%d����·��  \n\n",M.e);
		int a,b;
		for(a=0; a<M.v; a++){
			for(b=0; b<a; b++){
				if(M.edges[a][b]!=0){
					if(M.edges[a][b]!=INF){
						printf("\t		��%s�� <---> ��%s��,������%d�� \n",M.vexs[a].name,M.vexs[b].name,M.edges[a][b]);
					}
				}
			}
		}
	}
	system("pause");
}/*չʾ����ͼ�����б�*/ 
void Introduce(){
	system("cls");
	int n=0;
	if(M.v==0){
		printf("������ͼ��ʱ�޵ص㣡\n\n");
		system("pause");
		return ;
	}
	showjd();
	printf("\n��������Ҫ�鿴�ĵص���ţ�\n");
	while(1){
		scanf("%d",&n);
		if(n<1||n>M.v) printf("���������������������룡\n");
		else break;
	}
	printf("%s��",M.vexs[n-1].name);
	printf("%s\n",M.vexs[n-1].xinxi);
	system("pause");
}/*�鿴ĳһ�ص�����*/ 
void Changejd(){
	system("cls");
	int n;
	if(M.v<=0){
		printf("����ͼ���޵ص㣬�޷�������\n");
		system("pause");
		return ;
	}
	showjd();
	printf("��������Ҫ�޸ĵĵص���ţ�\n");
	scanf("%d",&n);
	while(n<=0||n>M.v){
		printf("���������������������룡\n");
		scanf("%d",&n);
	}
	char newName[50],newxinxi[1000];
	printf("�õص㵱ǰ��������:\n\n��%s��\n\n��������ĺ�����֣�\n",M.vexs[n-1].name);
	scanf("%s",newName);
	getchar();
	printf("�õص㵱ǰ�Ľ���Ϊ��\n\n%s\n\n��������ĺ��µĵص���ܣ�\n",M.vexs[n-1].xinxi);
	scanf("%s",newxinxi);
	getchar();
	strcpy(M.vexs[n-1].name,newName);
	strcpy(M.vexs[n-1].xinxi,newxinxi);
	printf("\n�ص���Ϣ�޸ĳɹ�!\n");
	system("pause");
}/*�ı�ص�����*/ 
void Increasejd(){
	system("cls");
	int a,d,i,m=0;
	if(M.v>JD){
		printf("�ص��Ѵ��������50������ǰ�޷���Ӿ��㣡\n");
		system("pause");
		return ;
	}
	char newName[50],newxinxi[1000];
	printf("��������Ҫ��ӵĵص�����\n");
	scanf("%s",newName);
	getchar();
	printf("�����롾%s���ص�Ľ��ܣ���������200�֣�\n",newName);
	scanf("%s",newxinxi);
	getchar();
	showjd();
	printf("�����������ص�����ڵص����:\n");
	scanf("%d",&m);
	while(m<0||m>M.v){
		printf("���������������������룡\n");
		scanf("%d",&m);
	}
	for(i=0; i<m; i++){
		printf("�������%d�����ڵص�Ĵ��ţ�\n",i+1);
		scanf("%d",&a);
		while(a<=0||a>M.v||M.edges[a-1][M.v]!=INF){
			if(a<=0||a>M.v) printf("���������������������룡��Χ��1~%d֮�䡣\n",M.v);
			if(M.edges[a-1][M.v]!=INF) printf("�벻Ҫ�����ظ������ڵص㣬�������룺\n");
			scanf("%d",&a);
		}
		printf("�����롾%s���롾%s��֮��ľ��룺\n",newName,M.vexs[a-1].name);
		scanf("%d",&d);
		while(d<=0||d>=INF){
			printf("������ľ����������������룺\n");
			scanf("%d",&d);
		}
		M.edges[a-1][M.v]=M.edges[M.v][a-1]=d;
	}
	strcpy(M.vexs[M.v].name,newName);
	strcpy(M.vexs[M.v].xinxi,newxinxi);
	M.v++;
	M.e=M.e+m;
	printf("�ص���ӳɹ�!\n");
	system("pause");
}/*�����µĽڵ�*/ 
void Deletejd(){
	system("cls");
	int a,i,j,c=0;
	if(M.v<1){
		printf("����ͼ���޵ص㣬�޷�ɾ����\n");
		system("pause");
		return ;
	}
	showjd();
	printf("��������Ҫɾ���ĵص��ţ�\n");
	scanf("%d",&a);
	while(a<1||a>M.v){
		printf("���������������������룡��Χ��1~%d֮�䡣\n",M.v);
		scanf("%d",&a);
	}
	printf("�ص㣺��%s������ɾ��...\n",M.vexs[a-1].name);
	for(i=0; i<M.v; i++){
		if(M.edges[a-1][i]!=INF) c++;
	}
	for(i=a-1; i<M.v; i++){
		M.vexs[i]=M.vexs[i+1];
	}
	for(i=0; i<M.v; i++){
		for(j=a-1; j<M.v; j++) M.edges[i][j]=M.edges[i][j+1];
	}
	for(i=0; i<M.v; i++){
		for(j=a-1; j<M.v; j++) M.edges[j][i]=M.edges[j+1][i];
	}
	M.v--;
	M.e=M.e-c;
	printf("�ص�ɾ���ɹ���\n");
	system("pause");
}/*ɾ���ڵ�*/ 
void Increaselj(){
	system("cls");
	int a,b,d;
	if(M.v<=1){
		if(M.v==1){
			printf("����ͼ��ֻ��һ���ص㣬�޷���ӵ�·��\n");
			system("pause");
			return ;
		}else{
			printf("����ͼ���޵ص㣬�޷���ӵ�·��\n");
			system("pause");
			return ;
		}
	}
	showjd();
	printf("��ǰ����ͼ�к���%d����·��\n",M.e);
	printf("��������Ҫ��ӵ�·�������ص���ţ��м�ʹ�ÿո������\n");
	scanf("%d %d",&a,&b);
	while(a<1||a>M.v||b<1||b>M.v||a==b){
		if(a==b) printf("������ĵص������ͬ�����������룡\n");
		else printf("���������������������룡��Χ��1~%d֮�䡣\n",M.v);
		scanf("%d %d",&a,&b);
	}
	if(M.edges[a-1][b-1]!=INF) printf("��%s���롾%s��֮���Ѿ�����һ����·�������ٴ���ӣ�\n",M.vexs[a-1].name,M.vexs[b-1].name);
	else{
		printf("�����롾%s���͡�%s��֮���·�ĳ��ȣ�\n",M.vexs[a-1].name,M.vexs[b-1].name);
		scanf("%d",&d);
		while(d<=0||d>=INF){
			printf("������ĳ����������������룡\n");
			scanf("%d",&d);
		}
		M.edges[a-1][b-1]=M.edges[b-1][a-1]=d;
		M.e++;
		printf("��·��ӳɹ�����ǰ����ͼ�к���%d����·��\n",M.e);
	}
	system("pause");
}/*�����µı�*/ 
void Deletelj(){
	int a,b;
	system("cls");
	if(M.v<=0){
		printf("����ͼ���޵ص㣬�޷�ɾ����\n");
		system("pause");
		return ;
	}
	if(M.e<=0){
		printf("����ͼ���޵�·���޷�ɾ����\n");
		system("pause");
		return ;
	}
	showjd();
	printf("��ǰ����ͼ��һ����%d����·\n",M.e);
	printf("��������Ҫɾ���ĵ�·��Ӧ�������ص���ţ��м�ʹ�ÿո������\n");
	scanf("%d %d",&a,&b);
	while(a<1||a>M.v||b<1||b>M.v||a==b){
		if(a==b) printf("������ĵص������ͬ�����������룡\n");
		else printf("���������������������룡��Χ��1~%d֮�䣬�ص���Ų�ͬ��\n",M.v);
		scanf("%d %d",&a,&b);
	}
	if(M.edges[a-1][b-1]>=INF) printf("%s��%s֮��û�е�·���޷�ɾ����\n",M.vexs[a-1].name,M.vexs[b-1].name);
	else{
		printf("����ɾ����%s���롾%s��֮��ĵ�·...\n",M.vexs[a-1].name,M.vexs[b-1].name);
		M.edges[a-1][b-1]=M.edges[b-1][a-1]=INF;
		M.e--;
		printf("��·ɾ���ɹ�����ǰ����ͼ�к���%d����·��\n",M.e);
	}
	system("pause");
}/*ɾ����*/ 
void Zdlj(){
	system("cls");
	int a,i,j,k,min,pre;
	int b[JD],minl[JD],shanl[JD];/*���ԭ���Ľڵ�������ɵ��յ㡢������·���ĳ��ȡ������һ��·��λ��*/ 
	if(M.v<=1){
		if(M.v==1){
			printf("����ͼ��ֻ��һ���ص㣬�޷���ѯ���·����\n");
			system("pause");
			return ;
		}else{
			printf("����ͼ���޵ص㣬�޷���ѯ���·����\n");
			system("pause");
			return ;
		}
	}
	if(M.e<=0){
		printf("����ͼ���޵�·���޷���ѯ���·����\n");
		system("pause");
		return ;
	}
	showjd();
	printf("�����������ڵص�λ�õĴ��ţ�\n");
	scanf("%d",&a);
	while(a<1||a>M.v){
		printf("���������������������룡��Χ��1~%d֮�䡣\n",M.v);
		scanf("%d",&a);
	}
	b[a-1]=1;
	for(i=0; i<M.v; i++){
		minl[i]=M.edges[a-1][i];
		shanl[i]=a-1;
		b[i]=0;
	}
	minl[a-1]=0;
	b[a-1]=1;
	shanl[a-1]=-1;
	for(i=0; i<M.v; i++){
		min=INF+1;
		for(k=1; k<M.v; k++){
			if(b[k]==0&&minl[k]<min){
				j=k;
				min=minl[k];
			}
		}
		b[j]=1;
		for(k=0; k<M.v; k++){
			if(b[k]==0&&(minl[j]+M.edges[j][k]<minl[k])){
				minl[k]=minl[j]+M.edges[j][k];
				shanl[k]=j;
			}
		}
	}
	int flag=1;
	for(i=0; i<M.v; i++){
		if(i!=a-1){
			if(minl[i]!=INF){
				flag=0;
				printf("%d��: %s",minl[i],M.vexs[i].name);
				pre=shanl[i];
				while(pre>=0){
					printf("  <--->  %s",M.vexs[pre].name);
					pre=shanl[pre];
				}
				printf("\n");
			}
		}
	}
	if(flag!=0) printf("��%s�����κεص�֮�䶼û�п�ͨ��·��\n",M.vexs[a-1].name);
	system("pause");
}/*�Ͻ�˹�����㷨��*/ 
void Zdlj_2(){
	system("cls");
	int a,b,i,j,k,min,pre,s[JD],minl[JD],shanl[JD];/*���ԭ���Ľڵ�������ɵ��յ㡢������·���ĳ��ȡ������һ��·��λ��*/ 
	if(M.v<=1){
		if(M.v==1){
			printf("����ͼ��ֻ��һ���ص㣬�޷���ѯ���·����\n");
			system("pause");
			return ;
		}else{
			printf("����ͼ���޵ص㣬�޷���ѯ���·����\n");
			system("pause");
			return ;
		}
	}
	if(M.e<=0){
		printf("����ͼ���޵�·���޷���ѯ���·����\n");
		system("pause");
		return ;
	}
	showjd();
	printf("��������Ҫ��ѯ����������ص����,�м��ÿո������\n");
	scanf("%d %d",&a,&b);
	while(a<1||a>M.v||b<1||b>M.v){
		printf("���������������������룡��Χ��1~%d֮�䡣\n",M.v);
		scanf("%d %d",&a,&b);
	}
	s[a-1]=1;
	for(i=0; i<M.v; i++){
		minl[i]=M.edges[a-1][i];
		shanl[i]=a-1;
		s[i]=0;
	}
	minl[a-1]=0;
	s[a-1]=1;
	shanl[a-1]=-1;
	for(i=0; i<M.v; i++){
		min=INF+1;
		for(k=1; k<M.v; k++){
			if(s[k]==0&&minl[k]<min){
				j=k;
				min=minl[k];
			}
		}
		s[j]=1;
		for(k=0; k<M.v; k++){
			if(s[k]==0&&(minl[j]+M.edges[j][k]<minl[k])){
				minl[k]=minl[j]+M.edges[j][k];
				shanl[k]=j;
			}
		}
	}
	if(minl[b-1]==INF) printf("��%s���롾%s���ص�֮��û�п�ͨ��·��\n",M.vexs[a-1].name,M.vexs[b-1].name);
	else {
		printf("��%s�� <---> ��%s��֮�����̾�����%d�ס� \n",M.vexs[b-1].name,M.vexs[a-1].name,minl[b-1]);
		pre=shanl[b-1];
		printf("·��Ϊ��%s",M.vexs[b-1].name);
		while(pre>=0){
			printf("  <--->  %s",M.vexs[pre].name);
			pre=shanl[pre];
		}
	}
	printf("\n");
	system("pause");
}/*�Ͻ�˹�����㷨�İ�*/ 
