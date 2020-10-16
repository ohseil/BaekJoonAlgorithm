#include "problem3.h"

#define inf 2000000000

void solution(int N, int M, int start, int end, vector<vector<int>> transports, vector<int> moneys) {
	
	vector<long long> dist(N, -inf);
	dist[start] = moneys[start];

	cout << endl << endl;
	for (auto a : dist)
		cout << a << " ";
	cout << endl << endl;

	// ������ ���ÿ� �����ϸ� ������ ���� �� �� �����Ƿ�, 
	// a -> b �� �����
	// b���� �� �� �ִ� �� - (a->b���� ���µ� ��� ���) ������ �����Ѵ�.
	for (int i = 0; i < transports.size(); i++) {
		transports[i][2] = moneys[transports[i][1]] - transports[i][2];
	}

	bool isCycle = false;

	for (int i = 0; i < N * 2; i++) {

		for (auto transport : transports) {

			int a = transport[0];
			int b = transport[1];
			int cost = transport[2];

			if (dist[a] == -inf)
				continue;

			if (dist[a] + cost > dist[b]) {

				dist[b] = dist[a] + cost;
				
				/*// N��° loop���� �������� dist ���� ������Ʈ ���� ��찡
				// �������� ���Ե� ����Ŭ�� �ְ� ���� ������ �� �� �ִٴ� �ǹ�.
				if (i >= N - 1 && b == end)
					isCycle = true;*/
			}

			if (i >= N - 1 && b == end && dist[a] + cost > 0)
				isCycle = true;
		}
	}

	cout << endl;
	for (auto a : dist)
		cout << a << " ";
	cout << endl;

	if (isCycle == true) {
		// ���� ������ �� �� �ִ� ���
		cout << "Gee" << endl;
	}
	else if (dist[end] == -inf) {
		// �������� �� �� ���� ���
		cout << "gg" << endl;
	}
	else {
		cout << dist[end] << endl;
	}
}

void solution2(int N, int M, int start, int end, vector<vector<int>> transports, vector<int> moneys) {

	vector<long long> dist(N, -inf);
	dist[start] = moneys[start];

	cout << endl << endl;
	for (auto a : dist)
		cout << a << " ";
	cout << endl << endl;

	// ������ ���ÿ� �����ϸ� ������ ���� �� �� �����Ƿ�,
	// a -> b �� �����
	// b���� �� �� �ִ� �� - (a->b���� ���µ� ��� ���) ������ �����Ѵ�.
	for (int i = 0; i < transports.size(); i++) {
		transports[i][2] = moneys[transports[i][1]] - transports[i][2];
	}

	bool isCycle = false;

	for (int i = 0; i < N * 2; i++) {

		for (auto transport : transports) {

			int a = transport[0];
			int b = transport[1];
			int cost = transport[2];

			if (dist[a] == -inf) continue;
			else if (dist[a] == inf) dist[b] = inf;
			else if (dist[a] + cost > dist[b]) {

				dist[b] = dist[a] + cost;

				// N��° loop���� �������� dist ���� ������Ʈ ���� ��찡
				// �������� ���Ե� ����Ŭ�� �ְ� ���� ������ �� �� �ִٴ� �ǹ�.
				if (i >= N - 1)
					dist[b] = inf;
			}
		}
	}

	cout << endl;
	for (auto a : dist)
		cout << a << " ";
	cout << endl;

	if (dist[end] == inf) {
		// ���� ������ �� �� �ִ� ���
		cout << "Gee" << endl;
	}
	else if (dist[end] == -inf) {
		// �������� �� �� ���� ���
		cout << "gg" << endl;
	}
	else {
		cout << dist[end] << endl;
	}
}


namespace problem3 {

	void execute() {

		int N, M, start, end;

		cin >> N >> start >> end >> M;

		vector<int> moneys(N, 0);
		vector<vector<int>> transports(M, vector<int>(3, 0));

		for (int i = 0; i < M; i++)
			cin >> transports[i][0] >> transports[i][1] >> transports[i][2];

		for (int i = 0; i < N; i++)
			cin >> moneys[i];

		solution(N, M, start, end, transports, moneys);

		cout << endl << endl;

		solution2(N, M, start, end, transports, moneys);
	}
}