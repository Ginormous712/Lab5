#include <iostream>
#include <vector>
#include <ctime>
#include "GraphMatrix.h"
#include "GraphAdjacencyStructure.h"
#include <Windows.h>
#include <conio.h>
using namespace std;
//tasks: 1,2
//task 5(через поиск в ширину)
//task 11
//task 14
//task 17
//task 19
//task 21
void test(bool);
void test2()
{
	std::cout << "\n\t\t1.	граф у вигляді матриці суміжностей\n";
	GraphMatrix g(1, true);
	g.rd(10, 25);
	
	std::cout << "\t2.	друк графу\n";
	g.print();
	std::cout << "\t3.	перетворити граф к структурі суміжності( лише в рамках пункту)\n";
	GraphAdjacencyStructure g2(0, 0);
	g2.setGraph(g.GetGraphAS());
	g2.print();
	std::cout << "\t4.	перевірити зв'язність графу - ";
	cout << g.isConnected();
	std::cout << "\t5.	обхід графу в глибину (якщо є вага, то обхід йде мешним шляхом)\n";
	g.Depth_firstSearch();
	std::cout << "\t6.	алгоритм Дейкстри\n";
	g.DijkstryAlgoritm(1);
	std::cout << "\t7.	топологічне сортування Кана\n";
	g.topologicalSort();
	std::cout << "\t8.	побудови кістякового дерева на основі пошуку в глибину\n";
	g.setGr(g.bildSpTree());
	std::cout << "\t9.	побудови мінімального кістякового дерева (Kruskal)\n";
	g.Kruskal();
	std::cout << "\t\t2.	граф у вигляді структури суміжностей\n";
	GraphAdjacencyStructure g3(1, true);
	g3.rd(10, 25);

	std::cout << "\t2.	друк графу\n";
	g3.print();
	std::cout << "\t3.	перетворити граф к структурі суміжності( лише в рамках пункту)\n";
	GraphMatrix g4(0, 0);
	g4.setGr(g3.getGraphM());
	g4.print();
	std::cout << "\t4.	перевірити зв'язність графу - ";
	cout << g3.isConnected();
	std::cout << "\t5.	обхід графу в глибину (якщо є вага, то обхід йде мешним шляхом)\n";
	g3.Depth_firstSearch();
	std::cout << "\t6.	алгоритм Дейкстри\n";
	g3.DijkstryAlgoritm(1);
	std::cout << "\t7.	топологічне сортування Кана\n";
	g3.topologicalSort();
	std::cout << "\t8.	побудови кістякового дерева на основі пошуку в глибину\n";
	g3.setGraph(g3.bildSpTree());
	std::cout << "\t9.	побудови мінімального кістякового дерева (Kruskal)\n";
	g3.Kruskal();
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	GraphMatrix Matrix(1,true);
	Matrix.rd(10,30);
	Matrix.DijkstryAlgoritm(1, 3);

	/*int r = 0;
	while (1)
	{
		std::cout << "Режими роботи:\n";
		std::cout << "1.	Інтерактивний діалоговий режим\n";
		std::cout << "2.	Демонстраційний режим\n";
		std::cout << "3.	Бенчмарк\n";
		std::cout << "4.	Вихід із программи\n";
		r = _getch() - 48;
		if (r == 1)
		{
			test(true);

		}
		else if (r == 2)
		{
			test2();
		}
		else if (r == 3)
		{
			unsigned int start_time, end_time, search_time;
			std::cout << "\n\t\t1.	граф у вигляді матриці суміжностей\n";
			GraphMatrix g(1, true);
			g.rd(10, 25);

			std::cout << "\n\t2.	друк графу\n";
			g.print();
			std::cout << "\n\t3.	перетворити граф к структурі суміжності( лише в рамках пункту)\n";
			GraphAdjacencyStructure g2(0, 0);
			g2.setGraph(g.GetGraphAS());
			g2.print();
			std::cout << "\n\t4.	перевірити зв'язність графу - ";
			start_time = clock();
			cout << g.isConnected();
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
			std::cout << "\n\t5.	обхід графу в глибину (якщо є вага, то обхід йде мешним шляхом)\n";
			start_time = clock();
			g.Depth_firstSearch();
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
			std::cout << "\n\t6.	алгоритм Дейкстри\n";
			start_time = clock();
			g.DijkstryAlgoritm(1);
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
			std::cout << "\n\t7.	топологічне сортування Кана\n";
			start_time = clock();
			g.topologicalSort();
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
			std::cout << "\n\t8.	побудови кістякового дерева на основі пошуку в глибину\n";
			start_time = clock();
			g.setGr(g.bildSpTree());
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
			std::cout << "\n\t9.	побудови мінімального кістякового дерева (Kruskal)\n";
			start_time = clock();
			g.Kruskal();
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
			std::cout << "\t\t2.	граф у вигляді структури суміжностей\n";
			GraphAdjacencyStructure g3(1, true);
			g3.rd(10, 25);

			std::cout << "\n\t2.	друк графу\n";
			g3.print();
			std::cout << "\n\t3.	перетворити граф к структурі суміжності( лише в рамках пункту)\n";
			GraphMatrix g4(0, 0);
			g4.setGr(g3.getGraphM());
			g4.print();
			std::cout << "\n\t4.	перевірити зв'язність графу - ";
			start_time = clock();
			cout << g3.isConnected();
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
			std::cout << "\n\t5.	обхід графу в глибину (якщо є вага, то обхід йде мешним шляхом)\n";
			start_time = clock();
			g3.Depth_firstSearch();
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
			std::cout << "\n\t6.	алгоритм Дейкстри\n";
			start_time = clock();
			g3.DijkstryAlgoritm(1);
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
			std::cout << "\n\t7.	топологічне сортування Кана\n";
			start_time = clock();
			g3.topologicalSort();
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
			std::cout << "\n\t8.	побудови кістякового дерева на основі пошуку в глибину\n";
			start_time = clock();
			g3.setGraph(g3.bildSpTree());
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
			std::cout << "\n\t9.	побудови мінімального кістякового дерева (Kruskal)\n";
			start_time = clock();
			g3.Kruskal();
			end_time = clock();
			cout << "час роботи:";
			cout << end_time - start_time;
		}
		else if(r==4)
				break;
		else continue;
	}
	*/
	
 }

void test(bool ch)
{
	if (ch)
	{
		int r = 0;
		while (1)
		{
			std::cout << "\n\t1.	операції с графами\n";
			while (1)
			{
				std::cout << "\n\t\t1.	граф у вигляді матриці суміжностей\n";
				std::cout << "\t\t2.	граф у вигляді структури суміжностей\n";
				std::cout << "\t\t3.	вихід\n";
				

				r = _getch() - 48;
				if (r == 1)
				{
					std::cout << "\n\t\t\t1.	створити довільний граф\n";
					std::cout << "\t\t\t2.	створити випадковий граф\n";
					std::cout << "\t\t\t3.	вихід\n";
					r = _getch() - 48;
					if (r == 1)
					{
						bool vag = false;
						std::cout << "ваговий граф 1 - так, 0 - ні\n";
						vag = _getch() - 48;
						std::cout << "кількість вершин\n";
						int count;
						cin >> count;
						GraphMatrix g(count, vag);
						while (1)
						{
							std::cout << "\n\t1.	додати ребро\n";
							std::cout << "\t2.	друк графу\n";
							std::cout << "\t3.	перетворити граф к структурі суміжності( лише в рамках пункту)\n";
							std::cout << "\t4.	перевірити зв'язність графу\n";
							std::cout << "\t5.	обхід графу в глибину (якщо є вага, то обхід йде мешним шляхом)\n";
							std::cout << "\t6.	алгоритм Дейкстри\n";
							std::cout << "\t7.	топологічне сортування Кана\n";
							std::cout << "\t8.	побудови кістякового дерева на основі пошуку в глибину\n";
							std::cout << "\t9.	побудови мінімального кістякового дерева (Kruskal)\n";
							std::cout << "\t0.	вихід\n";
							r = _getch() - 48;
							if (r == 1)
							{
								while (1)
								{
									bool ori = false;
									std::cout << "\n\tоріентоване? 1 - так, 0 - ні\n";
									ori =  _getch() - 48;
									std::cout << "\n\tперша вершина\n";
									int one, two,tree;
									cin >> one;
									std::cout << "\n\tдруга вершина\n";
									cin >> two;
									if (vag)
									{
										std::cout << "\n\tвага\n";
										cin >> tree;
										g.addEdge(one, two, tree,ori);
									}
									else
									{
										g.addEdge(one, two, ori);
									}
									std::cout << "\n\tінша функция 1 - так, 0 - ні\n";
									ori = _getch() - 48;
									if (ori)
										break;
								}
							}
							else if (r == 2)
							{
								g.print();
							}
							else if (r == 3)
							{
								GraphAdjacencyStructure g2(0,0);
								g2.setGraph(g.GetGraphAS());
								g2.print();
							}
							else if (r == 4)
							{
								cout << g.isConnected();
							}
							else if (r == 5)
							{
								g.Depth_firstSearch();
							}
							else if (r == 6)
							{
								std::cout << "\n\t1.	від заданої до заданої\n";
								std::cout << "\t2.	від заданої до всіх інших\n";
								std::cout << "\t3.	від всіх до всіх\n";
								r = _getch() - 48;
								if(r == 1)
								{
									int o, t;
									cout << "перша:";
									cin >> o;
									cout << "другаж:";
									cin >> t;
									g.DijkstryAlgoritm(o, t);
								}
								else if (r == 2)
								{
									int o;
									cout << "перша:";
									cin >> o;
									g.DijkstryAlgoritm(o);
								}
								else if (r == 3)
								{
									g.DijkstryAlgoritm();
								}
							}
							else if (r == 7)
							{
								g.topologicalSort();
							}
							else if (r == 8)
							{
								g.setGr(g.bildSpTree());
								g.print();
							}
							else if (r == 9)
							{
								g.Kruskal();
							}
							else if (r == 0)
							{
								goto end;
							}
							else continue;
						}

					}
					else if (r == 2)
					{
					bool vag = false;
					std::cout << "ваговий граф 1 - так, 0 - ні\n";
					vag = _getch() - 48;
					std::cout << "кількість вершин\n";
					int count,re;
					cin >> count;
					cout << "кількість ребер\n";
					cin >> re;
					GraphMatrix g(count, vag);
					g.rd(count, re);
					while (1)
					{
						std::cout << "\n\t1.	додати ребро\n";
						std::cout << "\t2.	друк графу\n";
						std::cout << "\t3.	перетворити граф к структурі суміжності( лише в рамках пункту)\n";
						std::cout << "\t4.	перевірити зв'язність графу\n";
						std::cout << "\t5.	обхід графу в глибину (якщо є вага, то обхід йде мешним шляхом)\n";
						std::cout << "\t6.	алгоритм Дейкстри\n";
						std::cout << "\t7.	топологічне сортування Кана\n";
						std::cout << "\t8.	побудови кістякового дерева на основі пошуку в глибину\n";
						std::cout << "\t9.	побудови мінімального кістякового дерева (Kruskal)\n";
						std::cout << "\t0.	вихід\n";
						r = _getch() - 48;
						if (r == 1)
						{
							while (1)
							{
								bool ori = false;
								std::cout << "\n\tоріентоване? 1 - так, 0 - ні\n";
								ori = _getch() - 48;
								std::cout << "\n\tперша вершина\n";
								int one, two, tree;
								cin >> one;
								std::cout << "\n\tдруга вершина\n";
								cin >> two;
								if (vag)
								{
									std::cout << "\n\tвага\n";
									cin >> tree;
									g.addEdge(one, two, tree, ori);
								}
								else
								{
									g.addEdge(one, two, ori);
								}
								std::cout << "\n\tінша функция 1 - так, 0 - ні\n";
								ori = _getch() - 48;
								if (ori)
									break;
							}
						}
						else if (r == 2)
						{
							g.print();
						}
						else if (r == 3)
						{
							GraphAdjacencyStructure g2(0, 0);
							g2.setGraph(g.GetGraphAS());
							g2.print();
						}
						else if (r == 4)
						{
							cout << g.isConnected();
						}
						else if (r == 5)
						{
							g.Depth_firstSearch();
						}
						else if (r == 6)
						{
							std::cout << "\n\t1.	від заданої до заданої\n";
							std::cout << "\t2.	від заданої до всіх інших\n";
							std::cout << "\t3.	від всіх до всіх\n";
							r = _getch() - 48;
							if (r == 1)
							{
								int o, t;
								cout << "перша:";
								cin >> o;
								cout << "другаж:";
								cin >> t;
								g.DijkstryAlgoritm(o, t);
							}
							else if (r == 2)
							{
								int o;
								cout << "перша:";
								cin >> o;
								g.DijkstryAlgoritm(o);
							}
							else if (r == 3)
							{
								g.DijkstryAlgoritm();
							}
						}
						else if (r == 7)
						{
							g.topologicalSort();
						}
						else if (r == 8)
						{
							g.setGr(g.bildSpTree());
							g.print();
						}
						else if (r == 9)
						{
							g.Kruskal();
						}
						else if (r == 0)
						{
							goto end;
						}
						else continue;
					}
					}
					else if (r == 3)
					{
						return;
					}
					else continue;
				}
				else if (r == 2)
				{
				std::cout << "\n\t\t\t1.	створити довільний граф\n";
				std::cout << "\t\t\t2.	створити випадковий граф\n";
				std::cout << "\t\t\t3.	вихід\n";
				r = _getch() - 48;
				if (r == 1)
				{
					bool vag = false;
					std::cout << "ваговий граф 1 - так, 0 - ні\n";
					vag = _getch() - 48;
					std::cout << "кількість вершин\n";
					int count;
					cin >> count;
					GraphAdjacencyStructure g(count, vag);
					while (1)
					{
						std::cout << "\n\t1.	додати ребро\n";
						std::cout << "\t2.	друк графу\n";
						std::cout << "\t3.	перетворити граф к структурі суміжності( лише в рамках пункту)\n";
						std::cout << "\t4.	перевірити зв'язність графу\n";
						std::cout << "\t5.	обхід графу в глибину (якщо є вага, то обхід йде мешним шляхом)\n";
						std::cout << "\t6.	алгоритм Дейкстри\n";
						std::cout << "\t7.	топологічне сортування Кана\n";
						std::cout << "\t8.	побудови кістякового дерева на основі пошуку в глибину\n";
						std::cout << "\t9.	побудови мінімального кістякового дерева (Kruskal)\n";
						std::cout << "\t0.	вихід\n";
						r = _getch() - 48;
						if (r == 1)
						{
							while (1)
							{
								bool ori = false;
								std::cout << "\n\tоріентоване? 1 - так, 0 - ні\n";
								ori = _getch() - 48;
								std::cout << "\n\tперша вершина\n";
								int one, two, tree;
								cin >> one;
								std::cout << "\n\tдруга вершина\n";
								cin >> two;
								if (vag)
								{
									std::cout << "\n\tвага\n";
									cin >> tree;
									g.addEdge(one, two, tree, ori);
								}
								else
								{
									g.addEdge(one, two, ori);
								}
								std::cout << "\n\tінша функция 1 - так, 0 - ні\n";
								ori = _getch() - 48;
								if (ori)
									break;
							}
						}
						else if (r == 2)
						{
							g.print();
						}
						else if (r == 3)
						{
							GraphMatrix g2(0, 0);
							g2.setGr(g.getGraphM());
							g2.print();
						}
						else if (r == 4)
						{
							cout << g.isConnected();
						}
						else if (r == 5)
						{
							g.Depth_firstSearch();
						}
						else if (r == 6)
						{
							std::cout << "\n\t1.	від заданої до заданої\n";
							std::cout << "\t2.	від заданої до всіх інших\n";
							std::cout << "\t3.	від всіх до всіх\n";
							r = _getch() - 48;
							if (r == 1)
							{
								int o, t;
								cout << "перша:";
								cin >> o;
								cout << "другаж:";
								cin >> t;
								g.DijkstryAlgoritm(o, t);
							}
							else if (r == 2)
							{
								int o;
								cout << "перша:";
								cin >> o;
								g.DijkstryAlgoritm(o);
							}
							else if (r == 3)
							{
								g.DijkstryAlgoritm();
							}
						}
						else if (r == 7)
						{
							g.topologicalSort();
						}
						else if (r == 8)
						{
							g.setGraph(g.bildSpTree());
							g.print();
						}
						else if (r == 9)
						{
							g.Kruskal();
						}
						else if (r == 0)
						{
							goto end;
						}
						else continue;
					}

				}
				else if (r == 2)
				{
					bool vag = false;
					std::cout << "ваговий граф 1 - так, 0 - ні\n";
					vag = _getch() - 48;
					std::cout << "кількість вершин\n";
					int count, re;
					cin >> count;
					cout << "кількість ребер\n";
					cin >> re;
					GraphAdjacencyStructure g(count, vag);
					g.rd(count, re);
					while (1)
					{
						std::cout << "\n\t1.	додати ребро\n";
						std::cout << "\t2.	друк графу\n";
						std::cout << "\t3.	перетворити граф к структурі суміжності( лише в рамках пункту)\n";
						std::cout << "\t4.	перевірити зв'язність графу\n";
						std::cout << "\t5.	обхід графу в глибину (якщо є вага, то обхід йде мешним шляхом)\n";
						std::cout << "\t6.	алгоритм Дейкстри\n";
						std::cout << "\t7.	топологічне сортування Кана\n";
						std::cout << "\t8.	побудови кістякового дерева на основі пошуку в глибину\n";
						std::cout << "\t9.	побудови мінімального кістякового дерева (Kruskal)\n";
						std::cout << "\t0.	вихід\n";
						r = _getch() - 48;
						if (r == 1)
						{
							while (1)
							{
								bool ori = false;
								std::cout << "\n\tоріентоване? 1 - так, 0 - ні\n";
								ori = _getch() - 48;
								std::cout << "\n\tперша вершина\n";
								int one, two, tree;
								cin >> one;
								std::cout << "\n\tдруга вершина\n";
								cin >> two;
								if (vag)
								{
									std::cout << "\n\tвага\n";
									cin >> tree;
									g.addEdge(one, two, tree, ori);
								}
								else
								{
									g.addEdge(one, two, ori);
								}
								std::cout << "\n\tінша функция 1 - так, 0 - ні\n";
								ori = _getch() - 48;
								if (ori)
									break;
							}
						}
						else if (r == 2)
						{
							g.print();
						}
						else if (r == 3)
						{
							GraphMatrix g2(0, 0);
							g2.setGr(g.getGraphM());
							g2.print();
						}
						else if (r == 4)
						{
							cout << g.isConnected();
						}
						else if (r == 5)
						{
							g.Depth_firstSearch();
						}
						else if (r == 6)
						{
							std::cout << "\n\t1.	від заданої до заданої\n";
							std::cout << "\t2.	від заданої до всіх інших\n";
							std::cout << "\t3.	від всіх до всіх\n";
							r = _getch() - 48;
							if (r == 1)
							{
								int o, t;
								cout << "перша:";
								cin >> o;
								cout << "другаж:";
								cin >> t;
								g.DijkstryAlgoritm(o, t);
							}
							else if (r == 2)
							{
								int o;
								cout << "перша:";
								cin >> o;
								g.DijkstryAlgoritm(o);
							}
							else if (r == 3)
							{
								g.DijkstryAlgoritm();
							}
						}
						else if (r == 7)
						{
							g.topologicalSort();
						}
						else if (r == 8)
						{
							g.setGraph(g.bildSpTree());
							g.print();
						}
						else if (r == 9)
						{
							g.Kruskal();
						}
						else if (r == 0)
						{
							goto end;
						}
						else continue;
					}
				}
				else if (r == 3)
				{
					return;
				}
				else continue;
				}
				else if (r == 3)
				{
					return;
				}
				else continue;
			}
		end:;
		}
	}
}
