/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
import java.util.TreeSet;


class Main
{
static int MAX = 100000;
static int SQRT = 320;
static ArrayList<Long> primes = new ArrayList<>();
static boolean marked[] = new boolean[MAX+1];

static void sieve() {
	marked[1] = true;
	int i = 2;
	for (; i <= SQRT; ++i) if (!marked[i]) {
		primes.add((long)i);
		for (int j = i*i; j <= MAX; j += i) marked[j] = true;
	}
	for (; i <= MAX; ++i) if (!marked[i]) primes.add((long)i);
}
static BigInteger LIM=new BigInteger("");
	static BigInteger binpow(BigInteger a,int n){
	if(n==0)return BigInteger.ONE;
	if(n%2!=0)return a.multiply(binpow(a.multiply(a),n/2));
	else return binpow(a.multiply(a),n/2);
}
	public static void main (String[] args) throws java.lang.Exception
	{
		sieve();
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		BigInteger dos=new BigInteger("2");
		BigInteger tres=new BigInteger("3");
		BigInteger lim=binpow(dos,64).subtract(BigInteger.ONE);
		LIM=lim;
		TreeSet<BigInteger> ans=new TreeSet<>();
		ans.add(BigInteger.ONE);
		for(int i=4;i<=64;i++){
			if(i%2==0||i%3==0){
				for(int j=0;j<primes.size();j++){
					BigInteger prod=BigInteger.ONE;
					for(int k=j;k<primes.size();k++){
						prod=prod.multiply(binpow(BigInteger.valueOf(primes.get(k)),i));
					//	System.out.println(prod);
						if(prod.compareTo(lim)<=0)ans.add(prod);
						else break;
					}
				}
			}
		}
		Iterator it=ans.iterator();
		while(it.hasNext()){
			out.println(it.next());
		}
		out.close();
	}
}
