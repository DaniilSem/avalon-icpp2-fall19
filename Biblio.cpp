#include"Biblio.hpp"
#include<iostream>
#include<fstream>
#include<string>

namespace dr
{
	int findIndex(Book data[], int left, int right, int value)
	{
		int middle = (left + right) / 2;
		if ((left == middle - 1) || (right == middle + 1))
		{
			std::cerr << "No book";
			return -1;
		}
		if (data[middle].Id == value)
		{
			return middle;
		}
		if (data[middle].Id > value)
		{
			return findIndex(data, left, middle - 1, value);
		}
		else
		{
			return findIndex(data, middle + 1, right, value);
		}
	}

	int findIndex(Book data[], int size, int value)
	{
		return findIndex(data, 0, size - 1, value);
	}

	int findIndex(Book data[], int left, int right, std::string value)
	{
		int middle = (left + right) / 2;
		if ((left == middle - 1) || (right == middle + 1))
		{
			std::cerr << "No book";
			return -1;
		}
		if (data[middle].Title == value)
		{
			return middle;
		}
		if (data[middle].Title > value)
		{
			return findIndex(data, left, middle - 1, value);
		}
		else
		{
			return findIndex(data, middle + 1, right, value);
		}
	}

	int findIndex(Book data[], int size, std::string value)
	{
		return findIndex(data, 0, size - 1, value);
	}
	struct Input
	{
		Book* book;
		int len;
	};
	Input Inputer()
	{
		std::ifstream fin("Biblio.bin", std::istream::in | std::istream::binary);
		if (!fin.is_open())
		{
			throw std::exception("File was not oppened");
		}
		fin.seekg(0, std::ios_base::end);
		int temp = fin.tellg() / sizeof(Book);
		fin.seekg(0);
		Book* book = new Book[temp];
		fin.read(reinterpret_cast<char*>(book), sizeof(Book) * temp);
		Input res;
		res.book = book;
		res.len = temp;
		fin.close();
		return res;
	}
	void adder()
	{
		Book book;
		std::cout << "You decided to add a new book\nPlese, enter Id\n";
		std::cin >> book.Id;
		std::cout << "Plese, enter title\n";
		std::cin >> book.Title;
		std::cout << "Plese, enter author\n";
		std::cin >> book.Author;
		std::cout << "Plese, enter price\n";
		std::cin >> book.Price;
		std::cout << "Plese, enter quantity\n";
		std::cin >> book.Quantity;
		std::ofstream fout("Biblio.bin", std::istream::out | std::istream::binary | std::istream::app);
		if (!fout.is_open())
		{
			throw std::exception("File was not oppened");
			return;
		}
		fout.write(reinterpret_cast<char*>(&book), sizeof(Book));
		fout.close();
		return;
	}
	void redactor()
	{

		std::cout << "You decided to redact a book\nPlese, enter Id\n";
		int id;
		std::cin >> id;
		Input in = Inputer();
		Book* book = in.book;
		for (int i = 0; i < in.len; ++i)
		{
			bool ch = false;
			for (int j = 0; j < i - 1; ++j)
			{
				if (book[j].Id > book[j + 1].Id)
				{
					Book temp = book[j];
					book[j] = book[j + 1];
					book[j + 1] = temp;
					ch = true;
				}
				if (ch == false)
				{
					break;
				}
			}
		}
		int num = findIndex(book, in.len, id);
		if (num == -1) { return; }
		std::cout << "Plese, enter new Id\n";
		std::cin >> book[num].Id;
		std::cout << "Plese, enter new title\n";
		std::cin >> book[num].Title;
		std::cout << "Plese, enter new author\n";
		std::cin >> book[num].Author;
		std::cout << "Plese, enter new price\n";
		std::cin >> book[num].Price;
		std::cout << "Plese, enter new quantity\n";
		std::cin >> book[num].Quantity;


		std::ofstream fout("Biblio.bin", std::istream::out | std::istream::binary | std::istream::end);
		if (!fout.is_open())
		{
			throw std::exception("File was not oppened");
			return;
		}

		fout.write(reinterpret_cast<char*>(book), sizeof(Book) * in.len);
	}
	void finder()
	{
		std::cout << "You decided to find a book\nPlese, enter the name\n";
		std::string name;
		std::cin >> name;
		Input in = Inputer();
		Book* books = in.book;
		for (int i = 0; i < in.len; ++i)
		{
			bool ch = false;
			for (int j = 0; j < i - 1; ++j)
			{
				if (static_cast<std::string>(books[j].Title) > static_cast<std::string>(books[j + 1].Title))
				{
					Book temp = books[j];
					books[j] = books[j + 1];
					books[j + 1] = temp;
					ch = true;
				}
				if (ch == false)
				{
					break;
				}
			}
		}
		int num = findIndex(books, in.len, name);
		if (num == -1) { return; }
		std::cout << std::endl
			<< "Id - " << books[num].Id << std::endl
			<< "Author - " << books[num].Author << std::endl
			<< "Title - " << books[num].Title << std::endl
			<< "Price - " << books[num].Price << std::endl
			<< "Quantity - " << books[num].Quantity << std::endl;


	}
	void lister()
	{
		Input in = Inputer();
		Book* books = in.book;
		std::string* sort = new std::string[in.len];
		for (int i = 0; i < in.len; ++i)
		{
			sort[i] = static_cast<std::string>(books[i].Author)
				+ static_cast<std::string>(books[i].Title);
		}
		for (int i = 0; i < in.len; ++i)
		{
			bool ch = false;
			for (int j = 0; j < i - 1; ++j)
			{
				if (sort[j] > sort[j + 1])
				{
					std::string temp = sort[j];
					sort[j] = sort[j + 1];
					sort[j + 1] = temp;
					Book tem = books[j];
					books[j] = books[j + 1];
					books[j + 1] = tem;
					ch = true;
				}
				if (ch == false) {
					break;
				}
			}
		}
		for (int i = 0; i < in.len; ++i)
		{
			std::cout << std::endl
				<< "Id - " << books[i].Id << std::endl
				<< "Author - " << books[i].Author << std::endl
				<< "Title - " << books[i].Title << std::endl
				<< "Price - " << books[i].Price << std::endl
				<< "Quantity - " << books[i].Quantity << std::endl;
		}
	}
	void stat()
	{
		Input in = Inputer();
		Book* books = in.book;
		int col, sum;
		col = 0;
		sum = 0;
		for (int i = 0; i < in.len; ++i)
		{
			col += books[i].Quantity;
			sum += books[i].Quantity * books[i].Price;
		}
		std::cout << "Quantity of books - " << col << std::endl
			<< "Price - " << sum;
	}
}