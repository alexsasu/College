import { Component, OnDestroy, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { Subscription } from 'rxjs';
import { PcComponentsService } from 'src/app/services/pc-components.service';
import { MatDialog, MatDialogConfig, MatDialogModule } from '@angular/material/dialog';
import { AddEditPcPartComponent } from '../../shared/add-edit-pc-part/add-edit-pc-part.component';
import { PcComponent } from 'src/app/interfaces/pc-component';
import { DataService } from 'src/app/services/data.service';
import { LoginUser } from 'src/app/interfaces/login-user';

@Component({
  selector: 'app-pc-components',
  templateUrl: './pc-components.component.html',
  styleUrls: ['./pc-components.component.scss']
})
export class PcComponentsComponent implements OnInit, OnDestroy {

  public subscription!: Subscription;
  public pcComponents: PcComponent[] = [];
  public loggedUser!: LoginUser;
  public user = {roles: [localStorage.getItem('Role')]};
  public displayedColumns = this.user.roles.includes('Admin') ? ['componentId', 'componentName', 'seller', 'recommendedForGaming', 'price', 'details', 'edit', 'delete'] : ['componentId', 'componentName', 'seller', 'recommendedForGaming', 'price', 'details'];

  constructor(
    private router: Router,
    private dataService: DataService,
    private pcComponentsService: PcComponentsService,
    public dialog: MatDialog
  ) { }

  ngOnInit() {
    this.subscription = this.dataService.currentUser.subscribe((user: LoginUser) => this.loggedUser = user);
    // console.log(this.loggedUser.email);
    this.pcComponentsService.getAllComponents().subscribe({
      next: (result: PcComponent[]) => {
        console.log(result);
        this.pcComponents = result;
      },
      error: (e) => console.error(e)
    });
  }

  ngOnDestroy() {
    this.subscription.unsubscribe();
  }

  public logout(): void {
    this.router.navigate(['/auth/login']);
  }

  public openModal(pcComponent?: PcComponent): void {
    const data = {
      pcComponent
    };
    const dialogConfig = new MatDialogConfig();
    dialogConfig.width = '550px';
    dialogConfig.height = '700px';
    dialogConfig.data = data;
    const dialogRef = this.dialog.open(AddEditPcPartComponent, dialogConfig);
    dialogRef.afterClosed().subscribe((result) => {
      console.log(result);
      if (result) {
        this.pcComponentsService.getAllComponents().subscribe({
          next: (result: PcComponent[]) => {
            console.log(result);
            this.pcComponents = result;
          },
          error: (e) => console.error(e)
        });
      }
    });
  }

  public viewComponentDetails(id: number): void {
    // console.log(id);
    this.router.navigate(['/pc-components/pc-part', id]);
  }

  public addNewComponent(): void {
    this.openModal();
  }

  public editComponent(component: PcComponent): void {
    this.openModal(component);
  }

  public deleteComponent(id: number): void {
    this.pcComponentsService.deleteComponent(id).subscribe({
      next: (result) => {
        // console.log(result);
        this.pcComponentsService.getAllComponents().subscribe({
          next: (result: PcComponent[]) => {
            console.log(result);
            this.pcComponents = result;
          },
          error: (e) => console.error(e)
        });
      },
      error: (e) => console.error
    });
  }

}
