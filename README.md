# 42_push_swap
push_swap 프로젝트는 C로 구현된 정렬 알고리즘입니다. 이 프로그램은 정수 목록을 입력으로 받아 두 개의 스택을 사용하여 목록을 오름차순으로 정렬할 수 있는 일련의 명령어를 생성합니다. 이 프로젝트의 목표는 가능한 적은 수의 명령어를 사용하여 목록을 정렬하는 것입니다.

![push_swap_visualizer](https://github.com/JeongRon/42_push_swap/blob/main/video/push_swap_shorts.gif)

---

## push_swap 첫 구상
	1. argc argv 체크 하기
		- 숫자가 아닌, 문자가 들어 올 때 처리
		- int 범위가 아닌 숫자가 들어 올 때 처리
		- 중복된 숫자가 있을 시 처리
	2. int 형 숫자가 맞을 시, a 스택 연결 리스트에 저장하기
	3. 명령어들 동작 만들기 
	4. 입력 받은 리스트들 값에 따라서 순서 인덱싱화 하기 
	5. 정렬 알고리즘 구현하기
