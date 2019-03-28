use NCR;
select empname, sal+isnull(comm,0)"Annual Salary", comm from emp where sal>isnull(comm,0) order by sal desc,empname;