#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
	
	sigset_t set;
	int result;

	sigemptyset(&set);	// 시그널 집합을 시그널이 없는 비어있는 상태로 초기화
	result = sigismember(&set, SIGALRM);
	printf("SIGALRM is %s a member\n", result ? "" : "not");
	sigaddset(&set, SIGALRM);	//	시그널 집합에 특정 시그널 추가
	result = sigismember(&set, SIGALRM);
	printf("SIGALRM is %s a member\n", result ? "" : "not");
	
	sigfillset(&set);	// 시그널 집합을 모든 시그널이 포함된 상태로 초기화
	result = sigismember(&set, SIGCHLD);
	printf("SIGCHLD is %s a member\n", result ? "" : "not");
	sigdelset(&set, SIGCHLD);	//	시그널 집합에서 특정 시그널 삭제
	result = sigismember(&set, SIGCHLD);
	printf("SIGCHLD is %s a member\n", result ? "" : "not");
	
	return 0;
}
