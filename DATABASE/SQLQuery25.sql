use NCR;
select empname, sal*12"Annual salary",job from emp where sal*12>36000 or job = 'CLERK';