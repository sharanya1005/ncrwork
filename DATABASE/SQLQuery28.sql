use NCR;


select max(hiredate) "recentlyjoined",deptno  from emp group by deptno order by recentlyjoined;