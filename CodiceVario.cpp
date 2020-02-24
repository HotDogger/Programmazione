int fib(int n)
{
	if(n <= 1) return n;
	else return fib(n-1) + fib(n-2);
}

int fattoriale(int n)
{
    int f; 
    if(n==1) return 1;
   	f = fattoriale(n-1)*n;
   	return f;
}

double eleva(double base, int esp)
{
    double ris;
    if (esp==0) return 1;
    ris = base * eleva(base, esp-1);
    return ris;
}

int mcd (int x, int y)
{
    if (y==0) return x;
    return mcd(y,x%y);
}

int ricercabinariaricorsiva(int array[], int inizio, int fine, int x)
{
    if(fine >= inizio)
    {
        int meta = inizio + (fine - inizio)/2;
        if(array[meta] == x) return meta;
        if(array[meta] > x) return ricercabinariaricorsiva(array,inizio,meta-1,x);
        else return ricercabinariaricorsiva(array,meta,fine,x);
    }		
    return -1;
}

int ricercabinariaiterativa(int array[], int inizio, int fine, int x)
{
	while(fine >= inizio)
	{
		int meta = inizio + (fine - inizio)/2;
		if(array[meta] == x) return m;
		if(array[meta] < x) inizio = meta + 1;
		else fine = meta - 1;
	}
	return -1;
}

void(InOrder(struct Nodo *radice)
{
	stack<Nodo *>s;
	Nodo *curr = radice;
	while(curr != NULL || s.empty() == false)
	{
		while(curr != NULL)
		{
			s.push(curr);
			curr = curr->left;
		}
		curr = s.tpo();
		s.pop();
		cout << curr->data << " ";
		curr = curr->right;
	}
}
