# 42_push_swap
![push_swap_visualizer](https://github.com/JeongRon/42_push_swap/blob/main/video/push_swap_shorts.gif)

---

# push_swap Mandatory

push_swap 프로젝트는 C로 구현된 정렬 알고리즘입니다. 이 프로그램은 a, b 스택과 11가지의 명령어를 활용합니다. 명령어를 가능한 한 적게 사용하여 a 스택에 있는 정렬되어 있지 않은 숫자 목록들을 -> a 스택에 오름차순으로 정렬되게끔 만드는 것이 목표입니다.
<br>

### **대략적인 로직 설명**

	0. argc, argv를 활용하여 정수 목록을 입력받습니다.

	1. 입력받은 정수 목록을 에러 체크합니다.
		- 에러 체크를 하면서, 정수 목록들을 **연결 리스트**에 추가합니다.
		- 에러 체크 사항들
			- 숫자가 아닌, 문자가 들어 왔는지
			- 중복된 숫자가 들어 왔는지
			- int형 범위의 숫자만 들어 왔는지

	2. 정렬에 필요한 info 구조체 초기화합니다.

	3. 정수 목록이 이미 정렬되어 있는지 확인합니다.

	4. 연결리스트의 정숫값에 따라서 **순서**를 정해줍니다.
		- 가장 작은 값부터 1번

	5. 정렬 알고리즘을 실행합니다. 
		- a, b 스택과 11가지의 명령어를 활용합니다.
		- 명령어를 가능한 한 적게 사용하여 a 스택에 있는 정렬되어 있지 않은 숫자들을 a 스택에 정렬되게끔 만드는 것이 목표입니다.

# push_swap Bonus

보너스 파트는 해당 프로젝트의 Checker 프로그램을 만드는 것입니다. 11가지의 명령어를 직접 여러 번 입력받게 설계하고, 입력받은 명령어로 인해 a, b 스택이 정렬되는 과정이 일어나게 합니다. 최종적으로 a 스택에 정수 목록이 오름차순으로 정렬되어있고, b 스택이 비어있는 상태라면 'OK', 그렇지 않으면 'KO', 도중에 에러가 발생한다면 'Error'를 출력합니다. 
<br>

### **대략적인 로직 설명**
	
	0. argc, argv를 활용하여 정수 목록을 입력받습니다.

	1. 입력받은 정수 목록을 에러 체크합니다.
		- 에러 체크를 하면서, 정수 목록들을 **연결 리스트**에 추가합니다.
		- 에러 체크 사항들
			- 숫자가 아닌, 문자가 들어 왔는지
			- 중복된 숫자가 들어 왔는지
			- int형 범위의 숫자만 들어 왔는지

	2. 정렬에 필요한 info 구조체 초기화합니다.

	3. 연결리스트의 정숫값에 따라서 **순서**를 정해줍니다.
		- 가장 작은 값부터 1번

	4. 입력받은 명령어를 실행합니다.
		- 가능한 명령어 : pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr
		- 입력받은 문자열이 해당 명령어가 아닐 시, 에러 표시를 합니다.
		- 입력받은 명령어를 모두 실행시킨 후, 정렬 상태를 확인합니다.
			- (정렬 O / a 스택 오름차순 정렬, b 스택 비어있음) : OK
			- (정렬 X) : KO
			- (올바르지 않은 입력들) : Error