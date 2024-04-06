#include<iostream>
#include<cmath>

struct SEdge {
	int a;
	int b;
	int w;
	SEdge(int a = 0, int b = 0, int w = 1) : a(a), b(b), w(w) {}
	SEdge(const SEdge& src) : a(src.a), b(src.b), w(src.w) {}
	~SEdge() {}
	void set(int a, int b, int w)
	{
		this->a = a;
		this->b = b;
		this->w = w;
	}
	friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
};

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();
	void PrintMatrix();
	void PrintEdges();
	void ReadMatrix(int vertexes, std::istream& stream);
	void ReadEdges(int edges, bool haveweight = false);
	int edgesCount();
	int roadsCount();
	int vertexCount();
	int power(int vertex);
	int countWrongRoads();
	void paintVertex(int colour, int vert);
	int progenitor(int a, int b, int e);
	int CountEgesfromVertex(int vertex);
	void getIndexesUnitedVertex(int vertex);
	void adjacencyList(int vertex);
	bool orientedMatrixOrNot();
	bool fullGraphOrNot(int vertex);
	bool tournamentOrNot(int vertex);

private:

	void init();
	void initMatrix();
	void initEdges();
	void initMatrixFromEdges();
	void initEdgesFromMatrix();
	int getVertexesCountFromEdges();
	int getEdgesCountFromMatrix();
	void dispose();
	void disposeMatrix();
	void disposeEdges();


	int _vertexes;
	int _edges;
	int** _matrix;
	SEdge* _edge;
};

int main(int argc, char* argv[])
{
	CGraph graph;
	int v = 0;
	std::cin >> v;
	int g = 0;
	std::cin >> g;
	graph.ReadEdges(g);
	graph.PrintMatrix();

	if (graph.tournamentOrNot(v))
	{
		std::cout << "YES";

	}
	else
	{
		std::cout << "NO";
	}

	return EXIT_SUCCESS;
}


CGraph::CGraph()
	: _vertexes(0), _edges(0), _matrix(nullptr), _edge(nullptr) {}

CGraph::CGraph(int vertexes, int edges)
	: _vertexes(vertexes), _edges(edges), _matrix(nullptr), _edge(nullptr)
{
	init();
}

CGraph::~CGraph()
{
	dispose();
}

void CGraph::PrintMatrix()
{
	if (_matrix == nullptr)
	{
		if (_edge == nullptr)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initMatrixFromEdges();
	}
	for (int i = 1; i < _vertexes; ++i)
	{
		for (int j = 1; j < _vertexes; ++j)
		{
			std::cout << _matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CGraph::PrintEdges()
{
	if (_edge == nullptr)
	{
		if (_matrix == nullptr)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initEdgesFromMatrix();
	}
	for (int i = 0; i < _edges; ++i)
	{
		std::cout << _edge[i] << std::endl;
	}
}

void CGraph::ReadMatrix(int vertexes, std::istream& stream)
{
	_vertexes = vertexes;
	initMatrix();
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			stream >> _matrix[i][j];
		}
	}
}

void CGraph::ReadEdges(int edges, bool haveweight)
{
	_edges = edges;
	initEdges();
	for (int i = 0; i < _edges; ++i)
	{
		std::cin >> _edge[i].a >> _edge[i].b;
		if (haveweight)
		{
			std::cin >> _edge[i].w;
		}
	}
}

int CGraph::edgesCount()
{
	if (_edge == nullptr)
	{
		initEdgesFromMatrix();
	}
	return _edges;
}

int CGraph::roadsCount()
{
	return edgesCount() / 2;
}

int CGraph::vertexCount()
{
	if (_matrix == nullptr)
	{
		initMatrixFromEdges();
	}
	return _vertexes;
}

int CGraph::power(int vertex)
{
	int r = 0;
	for (int i = 0; i < vertexCount(); ++i)
	{
		r += (_matrix[vertex][i] != 0);
	}
	return r;
}

void CGraph::init()
{
	dispose();
	initMatrix();
	initEdges();
}

void CGraph::initMatrix()
{
	if (_vertexes == 0)
	{
		return;
	}
	_matrix = new int* [_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_matrix[i] = new int[_vertexes] { 0 };
	}
}

void CGraph::initEdges()
{
	if (_edges == 0)
	{
		return;
	}
	_edge = new SEdge[_edges];
}

void CGraph::initMatrixFromEdges()
{
	disposeMatrix();
	_vertexes = getVertexesCountFromEdges();
	initMatrix();
	for (int i = 0; i < _edges; ++i)
	{
		_matrix[_edge[i].a][_edge[i].b] = _edge[i].w;
	}
}

int CGraph::getEdgesCountFromMatrix()
{
	int count = 0;
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			count += (_matrix[i][j] != 0);
		}
	}
	return count;
}

void CGraph::dispose()
{
	disposeMatrix();
	disposeEdges();
}

void CGraph::disposeMatrix()
{
	if (_matrix != nullptr)
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			delete[] _matrix[i];
		}
		delete[] _matrix;
		_matrix = nullptr;
	}
}

void CGraph::disposeEdges()
{
	if (_edge != nullptr)
	{
		delete[] _edge;
		_edge = nullptr;
	}
}


void CGraph::initEdgesFromMatrix()
{
	disposeEdges();
	_edges = getEdgesCountFromMatrix();
	initEdges();
	for (int i = 0, k = 0; i < _vertexes && k < _edges; ++i)
	{
		for (int j = 0; j < _vertexes && k < _edges; ++j)
		{
			if (_matrix[i][j] != 0)
			{
				_edge[k++].set(i + 1, j + 1, _matrix[i][j]);
			}
		}
	}
}

int CGraph::getVertexesCountFromEdges()
{
	int res = 0;
	for (int i = 0; i < _edges; ++i)
	{
		res = (res > _edge[i].a ? res : _edge[i].a);
		res = (res > _edge[i].b ? res : _edge[i].b);
	}
	return res + 1;
}

std::ostream& operator<<(std::ostream& stream, const SEdge& edge)
{
	stream << edge.a << " " << edge.b;
	if (edge.w > 1)
	{
		stream << " " << edge.w;
	}
	return stream;
}

int CGraph::countWrongRoads()
{
	int c = 0;
	for (int i = 0; i < edgesCount(); ++i)
	{
		for (int j = 0; j < edgesCount(); ++j)
		{
			if ((_edge[i].a == _edge[j].b) && (_edge[j].a == _edge[i].b) && (_edge[i].w != _edge[j].w))
			{
				c++;
			}
		}
	}
	return c / 2;
}
void CGraph::paintVertex(int colour, int vert)
{
	for (int i = 0; i < edgesCount(); ++i)
	{
		if (_edge[i].a == vert)
		{
			_edge[i].w = colour;
		}
	}
	initMatrixFromEdges();
}
int CGraph::progenitor(int a, int b, int e)
{
	if (a > (std::pow(2, e)) || b > (std::pow(2, e)))
	{
		return 0;
	}
	if (a == b)
	{
		return a;
	}
	if (a == 1 || b == 1)
	{
		return 1;
	}
	while ((a / 2) != (b / 2)) {
		a /= 2;
		b /= 2;
	}
	return a / 2;
}
int CGraph::CountEgesfromVertex(int vertex)
{
	int c = 0;
	initMatrixFromEdges();
	for (int i = 0; i < vertexCount(); ++i)
	{
		c += (_matrix[vertex + 1][i] != 0);
	}
	return c;
}

void CGraph::getIndexesUnitedVertex(int vertex)
{
	int i = 0;
	for (int j = 0; j < vertexCount(); ++j)
	{
		if (_matrix[vertex + 1][j] != 0)
		{
			std::cout << j << " ";
		}
	}
}
void CGraph::adjacencyList(int vertex)
{
	_vertexes = vertex + 1;
	initMatrix();
	for (int i = 0; i < vertex; ++i)
	{
		int roads = 0;
		std::cin >> roads;
		for (int j = 0; j < roads; ++j)
		{
			int k = 0;
			std::cin >> k;
			_matrix[i][k - 1] = 1;
		}
	}
	PrintMatrix();
}
bool CGraph::orientedMatrixOrNot()
{
	if (_matrix == nullptr)
	{
		initMatrixFromEdges();
	}
	bool orient = true;
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			if ((_matrix[i][j] == 1) && (_matrix[j][i] != 1))
			{
				orient = false;
			}
		}
	}
	return orient;
}
bool CGraph::fullGraphOrNot(int vertex)
{
	_vertexes = vertex;

	if (_matrix == nullptr)
	{
		initMatrixFromEdges();
	}

	int c = vertex;
	for (int i = 0; i < _vertexes; ++i)
		for (int j = 0; j < _vertexes; ++j) {
			{
				if (_matrix[i][j] == 1 || _matrix[j][i] == 1)
				{
					_matrix[i][j] = 1;
					_matrix[j][i] = 1;
				}
			}
		}
	for (int i = 0; i < _vertexes; ++i)
		for (int j = 0; j < _vertexes; ++j) {
			{
				if (_matrix[i][j] == 1 || _matrix[j][i] == 1)
				{
					c += 1;
				}
			}
		}

	return (c / vertex) == vertex;
}
bool CGraph::tournamentOrNot(int vertex)
{
	_vertexes = vertex;

	if (_matrix == nullptr)
	{
		initMatrixFromEdges();
	}

	int c = vertex;
	for (int i = 0; i < _vertexes; ++i)
		for (int j = 0; j < _vertexes; ++j) {
			{
				if (_matrix[i][j] == 1 && _matrix[j][i] == 0)
				{
					_matrix[i][j] = 1;
					_matrix[j][i] = 1;
				}
			}
		}
	for (int i = 0; i < _vertexes; ++i)
		for (int j = 0; j < _vertexes; ++j) {
			{
				if (_matrix[i][j] == 1 || _matrix[j][i] == 0)
				{
					c += 1;
				}
			}
		}

	return (c / (vertex)) == vertex;
}