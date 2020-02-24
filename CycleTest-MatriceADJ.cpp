#include <fstream>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

template<class H>
class Graph
{
private:
	int nodi, archi;
	H* nodo;
	H** adj;
	int* colore;
	int numcicli;
	int findIndex(H value)
	{
		for (int a = 0; a < nodi; a++)
		{
			if (value == nodo[a]) return a;
		}
		return -1;
	}
	void pdfs(int index)
	{
		int i = index;
		colore[i] = GRAY;
		for (int j = 0; j < nodi; j++)
		{
			if (adj[i][j] == 1)
			{
				if (colore[j] == WHITE) pdfs(j);
				else if (colore[j] == GRAY) numcicli++;
			}
		}
		colore[i] = BLACK;
	}
public:
	Graph(int nodi, int archi)
	{
		this->nodi = nodi;
		this->archi = archi;
		nodo = new H[nodi];
		adj = new H * [nodi];
		colore = new int[nodi];
		for (int a = 0; a < nodi; a++)
		{
			adj[a] = new H[nodi];
			colore[a] = WHITE;
			for (int b = 0; b < nodi; b++)
			{
				adj[a][b] = 0;
			}
		}
		numcicli = 0;
	}
	void init(ifstream& infile)
	{
		int cicli = 0;
		while (cicli < nodi)
		{
			H val;
			infile >> val;
			nodo[cicli] = val;
			cicli++;
		}
		for (int a = 1; a < nodi; a++)
		{
			for (int b = a; b > 0; b--)
			{
				if (nodo[b] < nodo[b - 1])
				{
					H tmp = nodo[b];
					nodo[b] = nodo[b - 1];
					nodo[b - 1] = tmp;
				}
			}
		}
		cicli = 0;
		while (cicli < archi)
		{
			char parentesi;
			H val1;
			H val2;
			infile >> parentesi;
			infile >> val1;
			infile >> val2;
			infile >> parentesi;
			int pos1 = findIndex(val1);
			int pos2 = findIndex(val2);
			adj[pos1][pos2] = 1;
			cicli++;
		}
	}
	void cycletest(ofstream &output) //DFS
	{
		for (int i = 0; i < nodi; i++)
		{
			if (colore[i] == WHITE)
			{
				pdfs(i);
			}
		}
		output << numcicli << endl;
	}
	void matriceadj(ofstream& outfile) //Print
	{
		for (int a = 0; a < nodi; a++)
		{
			outfile << "(";
			outfile << nodo[a];
			for (int b = 0; b < nodi; b++)
			{
				if (adj[a][b] == 1)
				{
					outfile << " ";
					outfile << nodo[b];
				}
			}
			outfile << ") ";
		}
		outfile << endl;
	}
};

int main()
{
	int task = 100;
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	while (task > 0)
	{
		int N, M;
		string tipo;
		infile >> N >> M >> tipo;
		if (tipo == "int")
		{
			Graph<int>* G = new Graph<int>(N, M);
			G->init(infile);
			G->cycletest(outfile);
		}
		else if (tipo == "double")
		{
			Graph<double>* G = new Graph<double>(N, M);
			G->init(infile);
			G->cycletest(outfile);
		}
		else if (tipo == "char")
		{
			Graph<char>* G = new Graph<char>(N, M);
			G->init(infile);
			G->cycletest(outfile);
		}
		task--;
	}
}
