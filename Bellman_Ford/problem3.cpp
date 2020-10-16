#include "problem3.h"

#define inf 2000000000

void solution(int N, int M, int start, int end, vector<vector<int>> transports, vector<int> moneys) {
	
	vector<long long> dist(N, -inf);
	dist[start] = moneys[start];

	cout << endl << endl;
	for (auto a : dist)
		cout << a << " ";
	cout << endl << endl;

	// 임의의 도시에 도착하면 무조건 돈을 벌 수 있으므로, 
	// a -> b 의 비용을
	// b에서 벌 수 있는 돈 - (a->b까지 가는데 드는 비용) 값으로 갱신한다.
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
				
				/*// N번째 loop에서 도착지의 dist 값이 업데이트 됐을 경우가
				// 도착지가 포함된 사이클이 있고 돈을 무한히 벌 수 있다는 의미.
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
		// 돈을 무한히 벌 수 있는 경우
		cout << "Gee" << endl;
	}
	else if (dist[end] == -inf) {
		// 도착지에 갈 수 없는 경우
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

	// 임의의 도시에 도착하면 무조건 돈을 벌 수 있으므로,
	// a -> b 의 비용을
	// b에서 벌 수 있는 돈 - (a->b까지 가는데 드는 비용) 값으로 갱신한다.
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

				// N번째 loop에서 도착지의 dist 값이 업데이트 됐을 경우가
				// 도착지가 포함된 사이클이 있고 돈을 무한히 벌 수 있다는 의미.
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
		// 돈을 무한히 벌 수 있는 경우
		cout << "Gee" << endl;
	}
	else if (dist[end] == -inf) {
		// 도착지에 갈 수 없는 경우
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