use NCR;
select empno,count(*) from emp group by empno having count(*)>1;