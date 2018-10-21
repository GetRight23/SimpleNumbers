#include "pch.h"
#include "AtkinsSieve.h"

AtkinsSieve::AtkinsSieve(size_t limit) {
	recalculate(limit);
}

void AtkinsSieve::recalculate(size_t limit) {
	size_t sqr_lim;
	size_t x2, y2;
	size_t i, j;
	size_t n;

	m_sieve.resize(limit + 1, false);
	m_sieve[2] = 1;
	m_sieve[3] = 1;

	sqr_lim = (int)sqrt((long double)limit);

	x2 = 0;
	for (i = 1; i <= sqr_lim; i++) {
		x2 += 2 * i - 1;
		y2 = 0;
		for (j = 1; j <= sqr_lim; j++) {
			y2 += 2 * j - 1;

			n = 4 * x2 + y2;
			if ((n <= limit) && (n % 12 == 1 || n % 12 == 5)) {
				m_sieve[n] = !m_sieve[n];
			}

			n -= x2;
			if ((n <= limit) && (n % 12 == 7)) {
				m_sieve[n] = !m_sieve[n];
			}

			n -= 2 * y2;
			if ((i > j) && (n <= limit) && (n % 12 == 11)) {
				m_sieve[n] = !m_sieve[n];
			}
		}
	}

	for (i = 5; i <= sqr_lim; i++) {
		if (m_sieve[i]) {
			n = i * i;
			for (j = n; j <= limit; j += n) {
				m_sieve[j] = 0;
			}
		}
	}
}

