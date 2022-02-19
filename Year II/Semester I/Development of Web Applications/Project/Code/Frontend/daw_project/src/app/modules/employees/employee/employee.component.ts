import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { Subscription } from 'rxjs';
import { Employee } from 'src/app/interfaces/employee';
import { EmployeesService } from 'src/app/services/employees.service';

@Component({
  selector: 'app-employee',
  templateUrl: './employee.component.html',
  styleUrls: ['./employee.component.scss']
})
export class EmployeeComponent implements OnInit {

  public subscription!: Subscription;
  public id!: number;
  public employee: Employee = {
    employeeId: 0,
    role: '',
    employeeLastName: '',
    employeeFirstName: '',
    salary: 0,
    phoneNumber: ''
  };

  constructor(
    private route: ActivatedRoute,
    private clientsService: EmployeesService
  ) { }

  ngOnInit(): void {
    this.subscription = this.route.params.subscribe(params => {
      this.id = +params['id'];
      if (this.id) {
        this.getClientById();
      }
    });
  }

  public getClientById(): void {
    this.clientsService.getEmployeeById(this.id).subscribe({
      next: (result: Employee) => {
        console.log(result);
        this.employee = result;
      },
      error: (e) => console.error(e)
    });
  }

}
