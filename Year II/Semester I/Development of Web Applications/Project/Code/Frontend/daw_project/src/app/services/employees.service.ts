import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { Employee } from '../interfaces/employee';

@Injectable({
  providedIn: 'root'
})
export class EmployeesService {

  public url = 'https://localhost:5001/api/Employee';

  public httpOptions = {
    headers: new HttpHeaders()
      .set('Authorization', 'Bearer ' + localStorage.getItem("jwt"))
  };

  constructor(
    public http: HttpClient
  ) { }

  public getEmployeeById(id: number): Observable<Employee> {
    return this.http.get<Employee>(`${this.url}/${id}`, this.httpOptions);
  }

  public getAllEmployees(): Observable<Employee[]> {
    return this.http.get<Employee[]>(`${this.url}/getAllEmployees`, this.httpOptions);
  }

  public addEmployee(employee: Employee): Observable<Employee[]> {
    return this.http.post<Employee[]>(`${this.url}`, employee, this.httpOptions);
  }

  public editEmployee(employee: Employee): Observable<Employee[]> {
    var employeeToReturn = [
      {
        value: employee.role,
        path: "/role",
        op: "replace"
      },
      {
        value: employee.employeeLastName,
        path: "/employeeLastName",
        op: "replace"
      },
      {
        value: employee.employeeFirstName,
        path: "/employeeFirstName",
        op: "replace"
      },
      {
        value: employee.salary,
        path: "/salary",
        op: "replace"
      },
      {
        value: employee.phoneNumber,
        path: "/phoneNumber",
        op: "replace"
      }
    ]
    return this.http.patch<Employee[]>(`${this.url}/${employee.employeeId}`, employeeToReturn, this.httpOptions);
  }

  public deleteEmployee(id: number): Observable<number> {
    const options = {
      headers: this.httpOptions.headers,
      body: id
    };
    return this.http.delete<number>(`${this.url}/${id}`, options);
  }

}