import java.util.Scanner;


public class EarningBiggestPrizeMoney {
	static int Max = Integer.MIN_VALUE;
	static int check[][] = new int[11][100000];	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();		
		for (int t = 1; t <=T; t++) {
			
			String n = sc.next();
			int ex = sc.nextInt();
			int num = n.length();
			int a[]=stringToIntArrays(n);		
			dequi(a, num, ex);
			System.out.println("Case #" + t);
			System.out.println(Max);
			Max = 0;
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 1000; j++) {
					check[i][j]=0;
				}
			}
		}
	}
	public static int[] stringToIntArrays(String number) {
		int d[] = new int[number.length()];
		for (int i = 0; i < d.length; i++) {
			d[i]=number.charAt(i)-'0';
		}
		return d;
	}
	public static void Swap(int a[], int x, int y) {
		int tmp = a[x];
		a[x] = a[y];
		a[y]=tmp;
	}
	public static int ArrayToNumber(int num, int a[]) {
		int s= 0;
		for (int i = 0; i < num; i++) {
			s=s*10+a[i];
		}
		return s;
	}
	public static boolean checkInsert( int s , int ex) {
		for (int i = 0; i < check[ex].length; i++) {
			if(check[ex][i]==s){
				return true;
			}else if (check[ex][i]==0) {
				check[ex][i]=s;
				break;
			}
		}
		return false;
	}
	public static void dequi(int a[] , int num , int ex) {
		if(ex == 0){
			int curenVal = ArrayToNumber( num ,a );
			if(curenVal> Max){
				Max = curenVal;
			}
			return;
		}
		for (int i = 0; i < num-1; i++) {
			for (int j = i+1; j < num; j++) {
				if(a[i]!=a[j]){
					Swap(a,i,j);
					int s =ArrayToNumber(num,a);
					if(!checkInsert(s, ex)){
						dequi(a,num, ex-1);
					}					
					Swap(a,i,j);
				}
			}
		}
	}
}
