import { Component, OnDestroy, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { DataService } from 'src/app/services/data.service';
import { Subscription } from 'rxjs';
import { EmployeesService } from 'src/app/services/employees.service';
import { MatDialog, MatDialogConfig, MatDialogModule } from '@angular/material/dialog';
import { AddEditEmployeeComponent } from '../../shared/add-edit-employee/add-edit-employee.component';
import { Employee } from 'src/app/interfaces/employee';

@Component({
  selector: 'app-employees',
  templateUrl: './employees.component.html',
  styleUrls: ['./employees.component.scss']
})
export class EmployeesComponent implements OnInit, OnDestroy {

  // public subscription!: Subscription;
  public parentMessage = 'Message from employees parent.';
  public employees: Employee[] = [];
  public displayedColumns = ['employeeId', 'role', 'employeeLastName', 'employeeFirstName', 'salary', 'phoneNumber', 'profile', 'edit', 'delete'];

  constructor(
    private router: Router,
    private dataService: DataService,
    private employeesService: EmployeesService,
    public dialog: MatDialog
  ) { }

  ngOnInit() {
    // this.subscription = this.dataService.currentUser.subscribe((user: User) => this.loggedUser = user);
    this.employeesService.getAllEmployees().subscribe({
      next: (result: Employee[]) => {
        console.log(result);
        this.employees = result;
      },
      error: (e) => console.error(e)
    });
  }

  ngOnDestroy() {
    // this.subscription.unsubscribe();
  }

  public logout(): void {
    this.router.navigate(['/auth/login']);
  }

  public receiveMessage(event: any): void {
    console.log(event);
  }

  public openModal(employee?: Employee): void {
    const data = {
      employee
    };
    const dialogConfig = new MatDialogConfig();
    dialogConfig.width = '550px';
    dialogConfig.height = '700px';
    dialogConfig.data = data;
    const dialogRef = this.dialog.open(AddEditEmployeeComponent, dialogConfig);
    dialogRef.afterClosed().subscribe((result) => {
      console.log(result);
      if (result) {
        this.employeesService.getAllEmployees().subscribe({
          next: (result: Employee[]) => {
            console.log(result);
            this.employees = result;
          },
          error: (e) => console.error(e)
        });
      }
    });
  }

  public viewEmployeeProfile(id: number): void {
    this.router.navigate(['/employees/employee', id]);
  }

  public addNewEmployee(): void {
    this.openModal();
  }

  public editEmployee(employee: Employee): void {
    this.openModal(employee);
  }

  public deleteEmployee(id: number): void {
    this.employeesService.deleteEmployee(id).subscribe({
      next: (result) => {
        this.employeesService.getAllEmployees().subscribe({
          next: (result: Employee[]) => {
            console.log(result);
            this.employees = result;
          },
          error: (e) => console.error(e)
        });
      },
      error: (e) => console.error
    });
  }

}
